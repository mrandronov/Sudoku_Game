
#include <iostream>

#include "SDL2/SDL.h"

#include "Button.h"
#include "Label.h"
#include "Board.h"

using namespace std;

Button::Button( int x, int y, int w, int h, string text, Action* action )
{
        box = ( SDL_Rect* ) malloc( sizeof( SDL_Rect ) );
        *( box ) = ( SDL_Rect ) { .x = x, .y = y, .w = w, .h = h };

        label = new Label( x, y, text, 20, "white" );
        label->center( w, h );

        this->action = action;
}

Button::Button( int x, int y, int w, int h, int size, string text, Action* action )
{
        box = ( SDL_Rect* ) malloc( sizeof( SDL_Rect ) );
        *( box ) = ( SDL_Rect ) { .x = x, .y = y, .w = w, .h = h };

        label = new Label( x, y, text, size, "white" );
        label->center( w, h );

        this->action = action;
}

void
Button::render()
{
        SDL_Renderer*           renderer = state->getRenderer();
        
        if ( this->isClick == true )
        {
                state->theme->setColor( renderer, "select_color" );
        }
        else if ( this->isHover == true )
        {
                state->theme->setColor( renderer, "highlight_color" );
        }
        else
        {
                state->theme->setColor( renderer, "default_color" );
        }
        SDL_RenderFillRect( renderer, box );

        label->render();
}

void
Button::onClick()
{
        this->isClick = true;
}

void
Button::clickUpdate()
{
        if ( action != nullptr )
        {
                action->action();
        }
        this->isClick = false;
}


Selector::Selector( int x, int y, int w, int h, string text, Action* action ) : 
        Button( x, y, w, h, 44, text, action ) {}

void
Selector::deselect()
{
        this->isClick = false;
        state->inputNumber = -1;
}

void
Selector::render()
{
        SDL_Renderer*           renderer = state->getRenderer();
        
        if ( this->isClick == true )
        {
                state->theme->setColor( renderer, "select_color" );
        }
        else if ( this->isHover == true )
        {
                state->theme->setColor( renderer, "highlight_color" );
        }
        else
        {
                state->theme->setColor( renderer, "default_color" );
        }
        SDL_RenderFillRect( renderer, box );

        label->render();
}

void
Selector::onClick()
{
        if ( !this->isClick )
        {
                this->isClick = true;
        }
        else
        {
                this->isClick = false;
        }
}

void
Selector::clickUpdate()
{
        board->setHighlightCells();
        if ( action == nullptr )
        {
                return;
        }

        if ( !this->isClick )
        {
                state->inputNumber = 0;
                return;
        }

        action->action();
}
