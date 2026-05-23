#include "sudoku.h"


// Function: is_val_in_row
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9); //checks if the row index given is even within the grid

  for(int n = 0; n < 9; n++){ //iterates through one row and returns whether the val already exists 
    if(sudoku[i][n] == val){
      return 1;
    }
  }

  return 0;
}

// Function: is_val_in_col
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9); //checks if column index given is even within the grid

for(int m = 0; m < 9; m++){ //iterates through one column and returns whether the val already exists
  if(sudoku[m][j] == val){
    return 1;
  }
}

  
  return 0;
}

// Function: is_val_in_3x3_zone
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9 && j>= 0 && j<9); //ensures both indexes are within the 9X9 grid
  

  int column_offset = j % 3; //these offsets help find which 3X3 grid to iterate 
  int row_offset = i % 3; 


  for(int l = i - row_offset; l < i - row_offset + 3; l++){ //subtracting by the offset calculated helps us pick right starting point
    for(int k = j - column_offset; k < j - column_offset + 3; k++){
      if(sudoku[l][k] == val){ //if we see val already exists, we can't add another one
        return 1; 
      }
    }
}
  
  return 0;
}

// Function: is_val_valid
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  if(is_val_in_row(val, i, sudoku) == 1 || is_val_in_col(val, j, sudoku) == 1 || is_val_in_3x3_zone(val, i, j, sudoku) == 1){
    return 0;  //combines the three functions for checking conditions into one, making it easier for solve_sudoku function
  }
  return 1;
}

// Procedure: solve_sudoku
int solve_sudoku(int sudoku[9][9]) {

  int i, j; //declare variables 

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){ //iterate through entire grid
      if(sudoku[i][j] == 0){ //if cell is empty, you want to add the correct val 
        for(int num = 1; num <= 9; num++){
          if(is_val_valid(num, i, j, sudoku)) { //uses the functions created earlier to finish task
            sudoku[i][j] = num; 

            if(solve_sudoku(sudoku)) {
              return 1; //if the puzzle is solved, we just want to finish the game
            }

            sudoku[i][j] = 0; 
          }
        }
        return 0;
      }
    }
  }
  return 1; 
}
// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}
