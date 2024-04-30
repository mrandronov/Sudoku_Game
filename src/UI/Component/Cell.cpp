
#include <iostream>

#include "SDL2/SDL.h"

#include "Cell.h"
#include "Board.h"
#include "../../State.h"

Cell::Cell( int x, int y, int i, int j, int val, bool isEnabled )
{
        this->box = ( SDL_Rect* ) malloc( sizeof( SDL_Rect ) );
        *( this->box ) = ( SDL_Rect ) { .x = x, .y = y, .w = CELL_SIZE, .h = CELL_SIZE };
        
        row = i;
        col = j;
        this->val = val;
        this->isEnabled = isEnabled;
        this->isHighlighted = false;

        update( val );
}

Cell::~Cell()
{
        delete label;
}

void
Cell::render()
{
        SDL_Renderer*           renderer = state->getRenderer();

        if ( this->isClick == true )
        {
                state->theme->setColor( renderer, "select_color" );
        }
        else if ( this->isHover == true || this->isHighlighted == true )
        {
                state->theme->setColor( renderer, "highlight_color" );
        }
        else
        {
                state->theme->setColor( renderer, "default_color" );
        }
        SDL_RenderFillRect( renderer, this->box );

        label->render();
}

void
Cell::update( int val )
{
        if ( val == -1 )
        {
                return;
        }

        this->val = val;
        string text = ( val == 0 ) ? " " : to_string( val );

        // A label ultimately is a precomputed texture
        // generated using text and a font type.
        // To have the label represent new text, it 
        // needs to be deleted and a new texture ( label 
        // object ) is made to replace it.

        delete label;

        label = new Label( this->box->x, this->box->y, text, 32, "white" );
        label->center( CELL_SIZE, CELL_SIZE );
}

void
Cell::onClick()
{
        this->isClick = true;
}

void
Cell::clickUpdate()
{
        // Update the cell if
        // 1. The cell is flagged as enabled
        // 2. The input number is not the same as the current cell value
        if ( this->isEnabled && state->inputNumber != this->val )
        {
                sudokuGame->addCellMove( this->row, this->col, state->inputNumber, this->val );
                this->update( state->inputNumber );
                
                if ( state->inputNumber != 0 )
                {
                        this->isHighlighted = true;
                }

                if ( sudokuGame->isComplete() )
                {
                        state->ui->addSolvedMessage();
                }
        }
        
        this->isClick = false;
}
