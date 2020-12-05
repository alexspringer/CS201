#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char ** read_in(char * name, int * col, int * row, int * sCol,
	int * sRow, int * eCol, int * eRow);

int remove_newline(char * array);
char ** build_maze(char * file_name, char ** maze, int col, int row);
void display_maze(char ** maze, int col, int row);
