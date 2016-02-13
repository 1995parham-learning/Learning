/*
 * In The Name Of God
 * ========================================
 * [] File Name : lines.c
 *
 * [] Creation Date : 13-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_SIZE 100
#define INITIAL_BUFFER_SIZE 16

char** IncreaseBuffer(char** buffer, int* buffer_size);
void PrintLines(char** lines, int total_lines);
int MinLineIndex(char** buffer, int i, int j);
void SwapLines(char** buffer, int i, int j);

int main(){
	char **buffer;
	int *buffer_size;
	int *line_size;
	int s,t;
	int i = 0;
	char *q;
	
	s = INITIAL_BUFFER_SIZE;
	buffer_size = &s;
	
	t = MAX_LINE_SIZE;
	line_size = &t;
	
	printf("Get lines:\n");
	buffer = malloc(sizeof(char *) * *buffer_size);
	buffer[0] = malloc(sizeof(char) * *line_size);
	while (1) {
		q = gets(buffer[i]);
		if (q == NULL) {
			i = i - 1;
			*buffer[i + 1] = '\0';
			break;
		}
		i++;
		buffer[i] = malloc(sizeof(char)**line_size);
		printf("%d%s\n", i, buffer[i]);
	}
}
