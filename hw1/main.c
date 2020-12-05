#include "maze.h"



int main(int argc, char ** argv){
	char ** maze;
	int x_axis, y_axis, startX, startY, endX, endY;
	int success, i;
	
	maze = read_in(maze, &x_axis, &y_axis, &startX, &startY, 
		&endX, &endY);

/*	if(maze == NULL){
		printf("Error reading. \n");
	}
	
	success = build_maze(maze, x_axis, y_axis);*/
	for(i = 0; i < y_axis; ++i){
		printf("do we get here?");
		free(maze[i]);
	}
	free(maze);

	



	return 1;
}
