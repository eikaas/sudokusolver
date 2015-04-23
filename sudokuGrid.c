/*
 * sudokuGrid.c
 * Robin Eikaas
 * 29.12.09
 * 12.01.11
 */

#include <stdio.h>
#include <stdlib.h>

#include "sudokuGrid.h"

void readGame(sudokuGrid game) {
    int c;
    int x = 0;
    while ((c = getchar()) != EOF && x <= MAX_CELL) {
        if ((c >= MIN_VALUE && c <= MAX_VALUE) || c == EMPTY_VALUE) {
            game[x] = c;
            x++;
        } else if (c == ' ' || c == 10) { } // Skip spaces and LF's.
          else {
            printf("Invalid sudoku character: %c - Aborting\n", c);
            abort();
        }
    }
}

void showGame(sudokuGrid game) {
//    printf(">in showGame\n");
    int row = 0;
    int line = 0;
    int x;
    for (x = 0; x < GRID_SIZE; x++) {
        printf("%c ", game[x]);
        if (row == 2 || row == 5) {
            printf(" ");
        }
        if (row == 8) {
            printf("\n");
            line++;
            row = 0;
        } else {
            row++;
        }
        if (line == 3) {
            printf("\n");
            line = 0;
        }
    }
}

void setCell (sudokuGrid game, cell location, value digit) {
    //printf(">in setCell\n");
    game[location] = digit;
}

value getCell (sudokuGrid game, cell location) {
    //printf(">in getCell\n");
    return game[location];
}

void clearCell (sudokuGrid game, cell location) {
    //printf(">in clearCell\n");
    /*printf(">in clearCell\n");*/
    game[location] = EMPTY_VALUE;
}


int isFull (sudokuGrid game) {
    //printf(">in isFull\n");
    int x;
    for (x = 0; x < GRID_SIZE; x++) {
        if (game[x] == EMPTY_VALUE) {
            //printf(">found EMPTY_VALUE in cell\n");
            return FALSE;
        }
    }
    return TRUE;
}


// This has to test wether every single cell in the collumn is different, 
// every cell in the row is different and every cell in the grid is different.
int isLegal(sudokuGrid game, cell location, value digit) {
    int x, y;
    int islegal = TRUE;

    // Check the cell row for dupes
    if (location >= 0 && location <= 8) { // first row
        if (chkRows(game, digit, 0, 8))
            islegal = FALSE;
    } else if ( location >= 9 && location <= 17) { // second row
        if (chkRows(game, digit, 9, 17))
            islegal = FALSE;
    } else if ( location >= 18 && location <= 26) { // Third row
        if (chkRows(game, digit, 18, 26))
            islegal = FALSE;
    } else if ( location >= 27 && location <= 35 ) { // Fourth row
        if (chkRows(game, digit, 27, 35))
            islegal = FALSE;
    } else if ( location >= 36 && location <= 44 ) { // Fifth row
        if (chkRows(game, digit, 36, 44))
            islegal = FALSE;
    } else if ( location >= 45 && location <= 53 ) { // Sixth row
        if (chkRows(game, digit, 45, 53))
            islegal = FALSE;
    } else if ( location >= 54 && location <= 62 ) { // Seventh row
        if (chkRows(game, digit, 54, 62))
            islegal = FALSE;
    } else if ( location >= 63 && location <= 71 ) { // Eight row
        if (chkRows(game, digit, 63, 71))
            islegal = FALSE;
    } else if ( location >= 72 && location <= 80 ) { // Ninth row
        if (chkRows(game, digit, 72, 80))
            islegal = FALSE;
    }

    // Check collumn for dupes

    if (islegal == TRUE) {
        for (x = 0; x < 9; x++) {
            if (col_a[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_a[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_b[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_b[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_c[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_c[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_d[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_d[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_e[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_e[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_f[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_f[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_g[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_g[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_h[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_h[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            } else if (col_i[x] == location) {
                for (y = 0; y < 9; y++) {
                    if (game[col_i[y]] == digit) {
                        islegal = FALSE;
                    }
                }
            }
        }
    }

    // Check grid boxes for dupes.
    if (islegal == TRUE) {
        if (location < 27) { // gbox = a,b or c
            for (x = 0; x < 9; x++) {
                if (gbox_a[x] == location) { // cell location is in block a
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_a[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                } else if (gbox_b[x] == location) {
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_b[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                } else if (gbox_c[x] == location) {
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_c[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                }
            }
        } else if (location > 26 && location < 54) { // gbox = d, e or f
            for (x = 0; x < 9; x++) {
                if (gbox_d[x] == location) { // cell location is in block a
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_d[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                } else if (gbox_e[x] == location) {
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_e[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                } else if (gbox_f[x] == location) {
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_f[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                }
            }
        } else { // gbox = g, h or i
            for (x = 0; x < 9; x++) {
                if (gbox_g[x] == location) { // cell location is in block a
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_g[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                } else if (gbox_h[x] == location) {
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_h[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                } else if (gbox_i[x] == location) {
                    for (x = 0; x < 9; x++) {
                        if (game[gbox_i[x]] == digit) {
                            islegal = FALSE;
                        }
                    }
                }
            }
        }
    }

    return islegal;
}

int chkRows(sudokuGrid game, value digit, int x, int y) {
    while (x <= y) {
        if (game[x] == digit)
            return TRUE;
        x++;
    }
    return FALSE;
}

cell getFreeCell(sudokuGrid game) {
    //printf(">in getFreeCell\n");

    int x;
    cell returnCell;
    for (x = 0; x < GRID_SIZE; x++) {
        if (game[x] == EMPTY_VALUE) {
            returnCell = x;
        }
    }
    return returnCell;
}

