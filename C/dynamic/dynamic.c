/*
 * In The Name Of God
 * ========================================
 * [] File Name : dynamic.c
 *
 * [] Creation Date : 18-01-2015
 *
 * [] Last Modified : Mon Jan 19 08:23:01 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

void get_a_function(void)
{
	FILE* f = fopen("fn.c", "w");
	fprintf(f, "#include <math.h>\n");
	fprintf(f, "\ndouble fn(double in)\n{\n\t");
	char *a_line = NULL;
	char *prompt = ">> double fn(double in)\n{\n\t";
	do {
		free(a_line);
		a_line = readline(prompt);
		fprintf(f, "\t%s\n", a_line);
		prompt = "\t";
	} while (strcmp(a_line, "}"));
	fclose(f);
}

void compile_and_run(void)
{
	if (system("c99 -fPIC -shared fn.c -o fn.so -lm") != 0) {
		printf("Compilation error.\n");
		return;
	}
	void *handle = dlopen("./fn.so", RTLD_LAZY);
	if (!handle)
		printf("Failed to load fn.so: %s\n", dlerror());
	typedef double (*fn_type)(double);
	fn_type f = dlsym(handle, "fn");
	printf("f(1) = %g\n", f(1));
	printf("f(2) = %g\n", f(2));
	printf("f(10) = %g\n", f(10));
}

int main(int argc, char *argv[])
{
	printf("I am about to run a function. But first, you have to write it for me\n");
	printf("Enter function body. Conclude with a '}' alone on a line.\n\n");
	get_a_function();
	compile_and_run();
}
