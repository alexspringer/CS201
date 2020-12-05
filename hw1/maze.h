#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



/*	Prototypes	*/
char ** read_in(char ** maze, int * x_axis, int * y_axis, int * startX, 
	int * startY, int * endX, int * endY);

int remove_newline(char * array);
char ** build_maze(char ** maze, int x_axis, int y_axis);
