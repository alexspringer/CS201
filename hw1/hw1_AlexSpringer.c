#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



int allocate_maze();
int fill_maze(char ** maze, int colm, int row, FILE * file);
void display_maze(char ** maze, int colm, int row);



int main(){
	int num;
	num = allocate_maze();
	return 0;
}



int allocate_maze(){

	long colm, row;
	char temp[20];
	char start[20], finish[20];
	char * ptr;
	char ** maze;
	FILE * file;
	int i, x, num;
	char * buffer;
	char * name;
	char temp2[200];

	/*printf("Enter the file you wish to open ");
	fgets(temp, 20, stdin);
	printf(temp);
	num = strlen(temp);
	printf("Size: %d \n", num);
	name = (char*)malloc(sizeof(char)*num);
	strncpy(name, temp, num);
	printf("%s \n", name);

	file = fopen(name, "r");*/
	file = fopen("maze3.txt" , "r");
	if(file != NULL){
		fgets(temp, 20, file);
		row = strtol(temp, &ptr, 10);
		printf("Row: %d ", row);
		colm = strtol(ptr + 1, NULL, 10);
		printf("Column: %d \n", colm);

		maze = (char**)malloc(sizeof(char*)*colm);
		for(i = 0; i < colm; ++i){
			maze[i] = (char*)malloc(sizeof(char)*row);
		}

		fgets(start, 20, file);
		printf("Start: %s", start);
		fgets(finish, 20, file);
		printf("Finish: %s \n", finish);

		buffer = (char*)malloc(sizeof(char)*row + 2);
		for(i = 0; i < colm; ++i){

			fgets(buffer, row + 2, file);
			printf("%s", buffer);

			/*fgets(temp2, 200, file);
			printf("%s", temp2);
			num = strlen(temp2);
			printf("%d ", num);*/
		}

		printf("\n");

	/*	display_maze(maze, colm, row);*/
	}
	else{
		printf("That file does not exist.");
	}


	return 1;
}



int fill_maze(char ** maze, int colm, int row, FILE * file){
	int i, x;
	char temp;
	if(file == NULL){
		printf("File is null");
		}
	for(i = 0; i < colm; ++i){
		for(x = 0; x < row; ++x){
			fgets(temp, 1, file);
		}
	}

	return 1;
}



void display_maze(char ** maze, int colm, int row){
	int i, x;
	for(i = 0; i < colm; ++i){
		printf("\n");
		for(x = 0; x < row; ++x){
			if(maze[i][x] == "\0") return;
			printf("%c", maze[i][x]);
		}
	}

	return;
}
