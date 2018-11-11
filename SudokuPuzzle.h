#ifndef _SUDOKU_PUZZLE_H2
#define _SUDOKU_PUZZLE_H2
#include"boardclass.h"
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QSize>
#include <QMouseEvent>
#include <iostream>
#include  <sstream>
#include<vector>
#include"ndataset.h"
#include<list>
#include<omp.h>
#include<tuple>
#include<stack>
/*
 * See SudokuPuzzle.cpp for implementation and detailed API.
 */
class SudokuPuzzle : public boardclass
{
  public:
    struct STACK
    {
      int x;
      int y;
      bool ret;
    };
	// Represents the boards state. 0 means "no value set yet", and 1-9 are valid values.
    //short int board[9][9];

    // Set to true to turn on tracers
    bool debug;
    //int zerocount;
    // Print tracer: print trying value
	void printTracerTryingValue(int x_cord, int y_cord);

    // Recursive method that solves board one block at time
	bool solve(int x_cord, int y_cord);

    // Verifies that set value at certain coordinate is valid
	bool verifyValue(int x_cord, int y_cord);

  public:
    // Constructor

      SudokuPuzzle();
    // Print puzzle in current state
    void print();

    // Set a value on the board. Used for laying out board and solving
    void setBoardValue(int x_cord, int y_cord, int value);

        // Get a value on the board.
    int getBoardValue(int x_cord, int y_cord);

    // Solve the puzzle. Returns true if in solved state, returns false if unsolvable.
    bool solve();
    bool allok();

};

#endif
