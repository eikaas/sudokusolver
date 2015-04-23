/*
 * testSudokuGrid.c
 * Robin Eikaas
 * 29.12.09
 * 12.01.11
 */

#include <stdio.h>
#include <assert.h>
#include "sudokuGrid.c"
#include "testSudokuGrid.h"

int main() {
    testSudokuGrid();
    return 0;
}

void testSudokuGrid() {
    printf("Testing sudokuGrid...\n");
    testClearCell();
    testSetCell();
}

void testClearCell() {
    printf(" * Testing clearCell(): ");
    sudokuGrid sample;
    clearCell(sample, 5);
    assert (sample[5] == '.');
    printf("OK!\n");
}

void testSetCell() {
    printf(" * Testing setCell(): ");
    sudokuGrid sample;
    setCell(sample, 9, 2);
    assert(sample[9] == 2);
    setCell(sample, 3, 5);
    assert(sample[3] == 5);
    printf("OK!\n");
}

void testGetFreeCell() {
    printf(" * Testing getFreeCell(): ");
}

