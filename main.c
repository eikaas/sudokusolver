/*
 * main.c
 * Robin Eikaas
 * 29.12.09
 */

#include <stdio.h>
#include "sudokuGrid.c"

int hasSolution(sudokuGrid game);

int guesses = 0;

int main(int argc, char *argv[]) {

    //testSudokuGrid();

    sudokuGrid sample;
    readGame (sample);

    if (hasSolution(sample)) {
        showGame (sample);
        printf("Guesses: %d\n", guesses);
    }

    return 0;

}

int hasSolution(sudokuGrid game) {
    int solved = FALSE;
    cell  candidateCell;
    value trialValue;

    if (isFull (game)) {
        printf("its full, complete\n");
        solved = TRUE;
    } else {

        candidateCell = getFreeCell (game);
        trialValue = MIN_VALUE;

        while (!solved && (trialValue <= MAX_VALUE)) {

            guesses++;
            if (isLegal (game, candidateCell, trialValue)) {
                setCell(game, candidateCell, trialValue);

                if (hasSolution (game)) {
                    solved = TRUE;
                } else {
                    clearCell (game, candidateCell);
                }
            }
            trialValue++;
        }
    }
    return solved;
}

