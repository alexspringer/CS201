#include "maze.h"



void display_maze(char ** maze, int x_axis, int y_axis){
	int i, j;
	for(i = 0; i < y_axis; ++i){
		for(j = 0; j < x_axis; ++j){
			if(maze[j][i] == '\0') return;
			printf("%c", maze[j][i]);
		}
	}
	return;
}



char ** build_maze(char ** maze, int x_axis, int y_axis){
	FILE * file;
	int j, currRow, success, counter;
	char buffer[x_axis+2];

	counter = 0;
	currRow = 0;

	printf("Please enter the name of the file you wish to open: ");
	fgets(buffer, 20, stdin);
	success = remove_newline(buffer);
	if(success == 1){
		printf("Successfully removed all newlines!\n");
		success = 0;
	}


	file = fopen(buffer, "r");
	if(file != NULL){
		printf("File opened... Reading...\n \n");
		while(fgets(buffer, sizeof(buffer), file)){
			printf("%s \n", buffer);
			if(counter > 2){
				for(j = 0; j < x_axis; ++j){
					maze[j][currRow] = (int) buffer[j];
				}
				++currRow;

			}
			++counter;
		}	

		fclose(file);
		/*display_maze(maze, x_axis, y_axis);*/
	}

	else{
		printf("File not found.\n");
	}

	return maze;
}



char ** read_in(char ** maze, int * x_axis, int * y_axis, int * startX, 
	int * startY,	int * endX, int * endY){
	
	char buffer[20];
	char * ptr;
	int counter, success, tempCol, i;
	int tempX, tempY;
	FILE * file;

	printf("Please enter the name of the file you wish to open: ");
	fgets(buffer, 20, stdin);
	success = remove_newline(buffer);
	if(success == 1){
		printf("Successfully removed all newlines!\n");
		success = 0;
	}


	file = fopen(buffer, "r");
	if(file != NULL){
		printf("File opened... Reading...\n \n");
		while(fgets(buffer, sizeof(buffer), file)){
			if(counter == 0){
				tempX = strtol(buffer, &ptr, 10);
				tempY = strtol(ptr + 1, NULL, 10);
				*y_axis = tempY;
				*x_axis = tempX;
				printf("X axis size: %d, Y axis size: %d \n"
					,tempX, tempY);
				maze = (char **) malloc(sizeof(char*) *tempX);
				for(i = 0; i < tempY; ++i){
					maze[i] = (char*)malloc(sizeof(char*)*tempY);
				}
			}

			if(counter == 1){
				*startX = strtol(buffer, &ptr, 10);
				*startY = strtol(ptr + 1, NULL, 10);
				printf("Starting coordinates: %d,%d \n", 
					*startX, *startY);
			}

			if(counter == 2){
				*endX = strtol(buffer, &ptr, 10);
				*endY = strtol(ptr + 1, NULL, 10);
				printf("Ending coordinates: %d,%d \n\n", 
					*endX, *endY);
			}

			++counter;
		}
		fclose(file);
		maze = build_maze(maze, *x_axis, *y_axis);

	}

	else{
		printf("File not found.\n");
	}

	return maze;
}



int remove_newline(char * array){
	int i, len;
	len = strlen(array);
	for(i = 0; i < len; ++i){
		if(array[i] == '\n'){
			array[i] = '\0';
		}
	}
	return 1;
}
