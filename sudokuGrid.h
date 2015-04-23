/*
 * sudokuGrid.h
 * Robin Eikaas
 * 29.12.09
 * 12.01.11
 */

#define MIN_VALUE '1'
#define MAX_VALUE '9'
#define EMPTY_VALUE '.'
#define NUM_VALUES (MAX_VALUE - MIN_VALUE + 1)
#define GRID_SIZE (NUM_VALUES * NUM_VALUES)
#define MAX_CELL (GRID_SIZE - 1)

#define TRUE 1
#define FALSE 0

#define DEBUG FALSE

typedef char value;
typedef int cell;
typedef value sudokuGrid [GRID_SIZE];

// Sudoku grid gboxes
int gbox_a[9] = {0,1,2,9,10,11,18,19,20};
int gbox_b[9] = {3,4,5,12,13,14,21,22,23};
int gbox_c[9] = {6,7,8,15,16,17,24,25,26};

int gbox_d[9] = {27,28,29,36,37,38,45,46,47};
int gbox_e[9] = {30,31,32,39,40,41,48,49,50};
int gbox_f[9] = {33,34,35,42,43,44,51,52,53};

int gbox_g[9] = {54,55,56,63,64,65,72,73,74};
int gbox_h[9] = {57,58,59,66,67,68,75,76,77};
int gbox_i[9] = {60,61,62,69,70,71,78,79,80};

// sudoku collumn arrays
int col_a[9] = {0,9,18,27,36,45,54,63,72};
int col_b[9] = {1,10,19,28,37,46,55,64,73};
int col_c[9] = {2,11,20,29,38,47,56,65,74};

int col_d[9] = {3,12,21,30,39,48,57,66,75};
int col_e[9] = {4,13,22,31,40,49,58,67,76};
int col_f[9] = {5,14,23,32,41,50,59,68,77};

int col_g[9] = {6,15,24,33,42,51,60,69,78};
int col_h[9] = {7,16,25,34,43,52,61,70,79};
int col_i[9] = {8,17,26,35,44,53,62,71,80};

// given a grid, replaces all the cells in that grid with characters read from standard input.
// EMPTY_VALUE means blank cell, digits stand for themselves, all other characters ignored
void readGame (sudokuGrid game);

// displays a sudoko grid in a format which can be read back by readGame
void showGame (sudokuGrid game);

// sets the specified cell to the specified digit.
// assumes cell and digit are in legal range
void setCell (sudokuGrid game, cell location, value digit);

// returns digit in specified cell, or EMPTY_VALUE if blank 
// assumes cell location is in legal range
value getCell (sudokuGrid game, cell location);

// sets the specified cell to be blank
// assumes cell location is in legal range
void clearCell (sudokuGrid game, cell location);

// returns 0 if game contains at least one blank cell, non-zero otherwise
int isFull (sudokuGrid game);

// non-zero iff it would be legal to set the specified cell to the specified 
// digit.  
// assumes cell location and digit are in legal range, location is currently empty,
// and current game has been generated by a sequence of legal digit placements
int isLegal(sudokuGrid game, cell location, value digit);

// returns the location of a blank cell, assumes there is at least one in game
cell getFreeCell(sudokuGrid game);

// returns most common digit in the grid
// if two+ are equally common return either.
// (so, if all empty return any)
value mostCommonValue(sudokuGrid game);

// Returns TRUE if digit is found in game array in the x->y range
// Returns FALSE otherwise.
int chkRows(sudokuGrid game, value digit, int x, int y);

