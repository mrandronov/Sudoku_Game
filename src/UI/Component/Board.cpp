
#include "Board.h"

Board::Board()
{
        addCells();
}

Board::~Board()
{
}

void
Board::addCell( int x, int y, int r, int c )
{
        int val = sudokuGame->getCellValue( r, c );
        bool isEnabled = ( val == 0 ) ? true : false;
        Cell* cell = new Cell( x, y, r, c, val, isEnabled );

        cells[ r ].push_back( cell );

        MouseHoverSubscriber* mouseHoverSubscriber = new MouseHoverSubscriber( *cell );
        cellMouseHoverSubscribers[ r ].push_back( mouseHoverSubscriber );
        mouseHoverPublisher->registerSubscriber( *mouseHoverSubscriber );

        MouseClickSubscriber* mouseClickSubscriber = new MouseClickSubscriber( *cell );
        cellMouseClickSubscribers[ r ].push_back( mouseClickSubscriber );
        mouseClickPublisher->registerSubscriber( *mouseClickSubscriber );
}

void
Board::addCells()
{
        // 9x9 board cells
        for ( int i = 0; i < 9; i++ )
        {
                cells.push_back( vector< Cell* > () );
                cellMouseHoverSubscribers.push_back( vector< MouseHoverSubscriber* > () );
                cellMouseClickSubscribers.push_back( vector< MouseClickSubscriber* > () );

                for ( int j = 0; j < 9; j++ )
                {
                        // The i and j values need to be flipped here to represent the
                        // cells in the correct rotation.
                        addCell( BOARD_START_X + j * CELL_SIZE, BOARD_START_Y + i * CELL_SIZE, i, j );
                }
        }
}

void
Board::drawGridLine( Cell* start, Cell* end, string color, bool isVertical = true )
{
        SDL_Renderer* renderer = state->getRenderer();

        int endXMod = CELL_SIZE;
        int endYMod = CELL_SIZE;

        if ( isVertical )
                endXMod = 0;
        else
                endYMod = 0;

        state->theme->setColor( renderer, color );
        SDL_RenderDrawLine( renderer, 
                                start->box->x, 
                                start->box->y, 
                                end->box->x + endXMod, 
                                end->box->y + endYMod );
}

void
Board::undoMove( vector< int > lastMove )
{
        int r = lastMove[ 0 ];
        int c = lastMove[ 1 ];
        int prevVal = lastMove[ 3 ];

        cells[ r ][ c ]->update( prevVal );

        if ( prevVal != 0 && prevVal == state->inputNumber )
        {
                cells[ r ][ c ]->isHighlighted = true;
        }
        else
        {
                cells[ r ][ c ]->isHighlighted = false;
        }
}

void
Board::setHighlightCells( bool isHighlighted, int val )
{
        for ( int i = 0; i < 9; i++ )
        {
                for ( int j = 0; j < 9; j++ )
                {
                        if ( val == 0 )
                        {
                                cells[ i ][ j ]->isHighlighted = isHighlighted;
                        }
                        else if ( cells[ i ][ j ]->val == val )
                        {
                                cells[ i ][ j ]->isHighlighted = isHighlighted;
                        }
                }
        } 
}

void
Board::reset()
{
        for ( int i = 0; i < 9; i++ )
        {
                for ( int j = 0; j < 9; j++ )
                {
                        mouseHoverPublisher->deleteSubscriber( *cellMouseHoverSubscribers[ i ][ j ] );
                        mouseClickPublisher->deleteSubscriber( *cellMouseClickSubscribers[ i ][ j ] );
                }
        }

        cells = vector< vector< Cell* > > ();

        addCells();
}

void
Board::render()
{
        // Render each individual cell
        for ( auto row : cells )
        {
                for ( auto cell : row )
                {
                        cell->render();
                }
        }

        // Sub lines ( one line for every row/column )
        for ( int i = 1; i < 9; i++ )
        {
                drawGridLine( cells[ 0 ][ i ], cells[ 8 ][ i ], "background" );
                drawGridLine( cells[ i ][ 0 ], cells[ i ][ 8 ], "background", false );
        }

        // Major lines ( at rows/column 3 and 6 )
        drawGridLine( cells[ 0 ][ 3 ], cells[ 8 ][ 3 ], "white" );
        drawGridLine( cells[ 0 ][ 6 ], cells[ 8 ][ 6 ], "white" );

        drawGridLine( cells[ 3 ][ 0 ], cells[ 3 ][ 8 ], "white", false );
        drawGridLine( cells[ 6 ][ 0 ], cells[ 6 ][ 8 ], "white", false );
}

void Board::onClick() {}

void Board::clickUpdate() {}
