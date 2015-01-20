/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 20-01-2015
 *
 * [] Last Modified : Tue Jan 20 21:40:31 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *args[])
{
	if (argc < 4) {
		fprintf(stderr, "usage: %s schematic file"
				"0-base output file 1-base output file", args[0]);
		return -1;
	}
	FILE *scheme_file = fopen(args[1], "r");
	FILE *base_0_file = fopen(args[2], "w");
	FILE *base_1_file = fopen(args[3], "w");
	int line_nr = 0;
	int cell_nr = 0;
	char line[1024];
	char *cell;
	while (fgets(line, 1024, scheme_file)) {	
		cell_nr = 0;
		printf("%s\n", line);
		cell = strtok(line, " ");
		while (cell) {
			printf("%s\n", cell);
			if (!strcmp(cell, "*")) {
				fprintf(base_0_file, "%d %d\n", cell_nr, line_nr);
				fprintf(base_1_file, "%d %d\n", cell_nr + 1, line_nr + 1);
			}
			cell_nr++;
			cell = strtok(NULL, " ");
		}
		line_nr++;
	}
	fprintf(base_0_file, "====\n");
	fprintf(base_0_file, "%d %d\n", line_nr, cell_nr);
	fprintf(base_1_file, "====\n");
	fprintf(base_1_file, "%d %d\n", line_nr, cell_nr);
	
	fclose(base_0_file);
	fclose(base_1_file);
}
