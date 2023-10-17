#include <iostream>
#include "Sudoku.h"
int main() {
    Sudoku *s =new Sudoku(R"(D:\ccc++\koty_pulsemestr\input.txt)");

    s->startGame();
    return 0;
}
