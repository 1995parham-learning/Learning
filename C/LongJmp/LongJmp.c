#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;
static jmp_buf env_new;

static void f2(void) { longjmp(env, 2); }

static void f1(int argc) {
  if (argc == 1)
    longjmp(env, 1);
  f2();
}

static void f3(void) { longjmp(env_new, 3); }

int main(int argc, char *argv[]) {
  switch (setjmp(env)) {
  case 0:
    printf("Calling f1() after initial setjmp()\n");
    f1(argc);
    break;
  case 1:
    printf("We jumped back from f1()\n");
    break;
  case 2:
    printf("We jumped back from f2()\n");
    break;
  case 3:
    printf("We jumped back from f3() with env\n");
    break;
  }
  switch (setjmp(env_new)) {
  case 0:
    printf("Calling f3() after initial setjmp()\n");
    f3();
    break;
  case 3:
    printf("We jumped back from f3() with env_new\n");
    break;
  }
  exit(EXIT_SUCCESS);
}
