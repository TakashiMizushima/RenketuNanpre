#include <iostream>
#include "SudokuPuzzle.h"

/*
 * Create and solve a Sudoku puzzle. Will print
 * the board, then try to solve. If solves, will
 * print the solution. If unsolvable, will display
 * message.
 */
int mainpuzzle (int data1[][9],int data2[][9]) {
    
	SudokuPuzzle puzzle;
	
	/*
	 * Create board below. For each initial
	 * value on the board, specify using:
	 * 
	 * puzzle.setBoardValue(int x-cord, y-cord, val);
	 *
	 * Where:
	 *   x-cord: X coordinate on the Sudoku field.
     *   y-cord: Y coordinate on the Sudoku field.
	 *   val:    The value to place on the board.
	 *
	 * Use the following to determine x- and y- 
	 * coordinates:
	 *
	 *       X
	 *        0  1  2   3  4  5   6  7  8
	 *      -------------------------------
	 * Y 0  | .  .  . | .  .  . | .  .  . |
	 *   1  | .  .  . | .  .  . | .  .  . |
	 *   2  | .  .  . | .  .  . | .  .  . |
	 *      -------------------------------
	 *   3  | .  .  . | .  .  . | .  .  . |
	 *   4  | .  .  . | .  .  . | .  .  . |
	 *   5  | .  .  . | .  .  . | .  .  . |
	 *      -------------------------------
	 *   6  | .  .  . | .  .  . | .  .  . |
	 *   7  | .  .  . | .  .  . | .  .  . |
	 *   8  | .  .  . | .  .  . | .  .  . |
	 *      -------------------------------
	 *
	 */
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(data1[i][j]!=0)
            {
                puzzle.setBoardValue(i,j,data1[i][j]);
            }
        }
    }


	
	// Now solve. If not solvable, say.
	if (puzzle.solve()) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                data2[i][j]=puzzle.dataget(i,j);
            }
        }
	  
    }    return 0;
	
} // main
