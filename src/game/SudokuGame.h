#ifndef __LIB_SUDOKU_GAME_H__
#define __LIB_SUDOKU_GAME_H__

#include <iostream>
#include <vector>

using namespace std;

class SudokuGame
{
        private:
                string                          name;
                vector< vector< int > >         cells;
                vector< vector< int > >         solution;
                vector< vector< int > >         moves;

                bool                            checkRow( int row );
                bool                            checkCol( int col );
                bool                            checkBox( int row, int col );

        public:
                SudokuGame();
                SudokuGame( string problemFilePath );

                int                     readProblem( string problemFilePath );
                int                     getCellValue( int r, int c );
                void                    addCellMove( int r, int c, int val, int prevVal );
                vector< int >           undoCellMove();
                bool                    isComplete();
                void                    reset( string puzzle_path );
};

extern SudokuGame* sudokuGame;

#endif /* __LIB_SUDOKU_GAME_H__ */