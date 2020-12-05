#include "hw1.h"



int main(int argc, char * argv[]){
  char ** maze;
  char name[100];
  int col, row, sCol, sRow, eCol, eRow;
  
  printf("What is the name of the file we will open? ");
  fgets(name, 100, stdin);
  remove_newline(name);

  maze = read_in(name, &col, &row, &sCol, &sRow, &eCol, &eRow);
  display_maze(maze,col,row);



  return 1;
}



void display_maze(char ** maze, int col, int row){
  int x,y;
  for(y = 0; y < row; ++y){
    for(x = 0; x < col; ++x){
    	if(maze[y][x] == '\0') return;
	printf("%c", maze[y][x]);
    }
    printf("\n");
  }
  return;
}



char ** build_maze(char * file_name, char ** maze, int col, int row){
  FILE * file;
  char * buffer;
  char temp[20];
  int currRow, i, j, num;
  file = fopen(file_name, "r");

  /* Not sure why I needed to add three to the buffer! but it works! */
  currRow = 0; num = col + 3;

  buffer = malloc(sizeof(char*)*num);
  for(i = 0; i < 3; ++i){
    fgets(temp, 20, file);
  }

  if(file != NULL){
    while(fgets(buffer, num, file)){
	for(j = 0; j < col; ++j){
	  maze[currRow][j] = (int) buffer[j];
	}
	++currRow;
      }
    fclose(file);
  }
  free(buffer);  
  return maze;
}



char ** read_in(char * name, int * col, int * row, int * sCol, 
	int * sRow, int * eCol, int * eRow){

  FILE * file;
  char ** maze;
  char buffer[20];
  char * endptr;
  int tempCol, tempRow, i;

  if(!name) return NULL;
  file = fopen(name, "r");
  if(file == NULL) return NULL;

  if(file){
    printf("File exists... opening file. \n");
  
    /* Reading in the maze parameters */
    fgets(buffer, 20, file);
    *col = strtol(buffer, &endptr, 0);
    *row = strtol(endptr + 1, NULL, 0);
    tempCol = *col;
    tempRow = *row;

    /*Use the parameters of the maze to allocate it.*/
    maze = (char**) malloc(sizeof(char*)*tempRow);
    for(i = 0; i < tempRow; ++i){
      maze[i] = (char*) malloc(sizeof(char)*tempCol);
    }
    
    /* Reading in the maze starting coord */
    fgets(buffer, 20, file);
    *sCol = strtol(buffer, &endptr, 0);
    *sRow = strtol(endptr + 1, NULL, 0);

    /* Reading in the maze ending coord */
    fgets(buffer, 20, file);
    *eCol = strtol(buffer, &endptr, 0);
    *eRow = strtol(endptr + 1, NULL, 0);

    /* Display all of the data read in */
    fgets(buffer, 20, file);
    printf("Num columns: %d, Num Rows: %d \n", *col, *row);
    printf("Starting location: %d,%d\nEnding location: %d,%d\n",
      *sCol,*sRow,*eCol,*eRow);

  }
  fclose(file);
  maze = build_maze(name, maze, *col, *row);
  return maze;
}



int remove_newline(char * array){
  int i;
  for(i = 0; i < strlen(array); ++i){
    if(array[i] == '\n'){
      array[i] = '\0';
    }
  }

    return 1;
}
