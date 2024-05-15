#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "SudokuGame.h"

using namespace std;

SudokuGame::SudokuGame()
{
        for ( int i = 0; i < 9; i++ )
        {
                cells.push_back( vector< int > ( 9, 0 ) );
                solution.push_back( vector< int > ( 9, 0 ) );
        }
}

SudokuGame::SudokuGame( string puzzleFilePath )
{
        for ( int i = 0; i < 9; i++ )
        {
                cells.push_back( vector< int > ( 9, 0 ) );
                solution.push_back( vector< int > ( 9, 0 ) );
        }

        this->readProblem( puzzleFilePath );
}

int
SudokuGame::readProblem( string puzzleFilePath )
{
        string line;
        fstream file( puzzleFilePath );

        // First line is the puzzle name
        getline( file, this->name );

        // Second line is the unsolved puzzle;
        getline( file, line );
        for ( int i = 0; i < 81; i++ )
        {
                cells[ i / 9 ][ i % 9 ] = line[ i ] - '0';
        }

        // Third line is the solution;
        getline( file, line );
        for ( int i = 0; i < 81; i++ )
        {
                solution[ i / 9 ][ i % 9 ] = line[ i ] - '0';
        }
        
        return 0;
}

int
SudokuGame::getCellValue( int r, int c )
{
        return cells[ r ][ c ];
}

void
SudokuGame::addCellMove( int r, int c, int val, int prevVal )
{
        moves.push_back( { r, c, val, prevVal } );
}

vector< int >
SudokuGame::undoCellMove()
{
        if ( moves.size() == 0 )
        {
                return {};
        }
        vector< int > top = moves.back();
        moves.pop_back();

        return top;
}

bool
SudokuGame::isCellValueCorrect( int r, int c, int val )
{
        return solution[ r ][ c ] == val;
}

bool
SudokuGame::checkRow( int row )
{
        vector< int > nums( 9, 0 );
        for ( int i = 0; i < 9; i++ )
        {
                if ( nums[ cells[ row ][ i ] ] != 0 )
                {
                        return false;
                }

                nums[ cells[ row ][ i ]  ] += 1;
        }

        return true;
}

bool
SudokuGame::checkCol( int col )
{
        vector< int > nums( 9, 0 );
        for ( int i = 0; i < 9; i++ )
        {
                if ( nums[ cells[ i ][ col ] ] != 0 )
                {
                        return false;
                }

                nums[ cells[ i ][ col ] ] += 1;
        }

        return true;
}

bool
SudokuGame::checkBox( int row, int col )
{
        vector< int > nums( 9, 0 );

        int i_pos = row * 3;
        int j_pos = col * 3;

        for ( int i = i_pos; i < i_pos + 3; i++ )
        {
                for ( int j = j_pos; j< j_pos + 3; j++ )
                {
                        if ( nums[ cells[ i ][ j ] ] != 0 )
                        {
                                return false;
                        }

                        nums[ cells[ i ][ j ] ] += 1;
                }
        }

        return true;
}

bool
SudokuGame::isComplete()
{
        // Check all rows and columns
        for ( int i = 0; i < 9; i++ )
        {
                if ( !( checkRow( i ) && checkCol( i ) ) )
                {
                        return false;
                }
        }

        // Check each 3x3 box
        for ( int i = 0; i < 3; i++ )
        {
                for ( int j = 0; j < 3; j++ )
                {
                        if ( !checkBox( i, j ) )
                        {
                                return false;
                        }
                }
        }

        return true;
}

void
SudokuGame::reset( string puzzle_path )
{
        cells.clear();
        solution.clear();
        moves.clear();
}
