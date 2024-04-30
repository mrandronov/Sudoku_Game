
#include <iostream>
#include <algorithm>

#include "SDL2/SDL.h"

#include "UI.h"
#include "Component/Label.h"
#include "Component/Button.h"
#include "Component/Cell.h"
#include "Component/Board.h"
#include "Component/SelectorPanel.h"
#include "../State.h"

UIEventPublisher< pair< int, int > >*           mouseHoverPublisher;
UIEventPublisher< SDL_Event >*                  mouseClickPublisher;
Board*                                          board;

template< typename T >
void
UIEventPublisher< T >::registerSubscriber( SubscriberIf< T >& subscriber )
{
        subscribers.push_back( &subscriber );
}

template< typename T >
void
UIEventPublisher< T >::deleteSubscriber( SubscriberIf< T >& subscriber )
{
        for ( auto it = this->subscribers.begin(); it != this->subscribers.end(); )
        {
                if ( *it == &subscriber )
                {
                        it = this->subscribers.erase( it );
                }
                else
                {
                        it++;
                }
        }
}

template< typename T >
void
UIEventPublisher< T >::publishData( T data )
{
        for ( auto subscriber : subscribers )
        {
                subscriber->recvPublishedData( data );
        }
}

template class UIEventPublisher< pair< int, int > >;
template class UIEventPublisher< SDL_Event >;

template< typename T >
void
UIComponent< T >::render()
{
        component->render();
}

void
UI::addComponent( Component* component )
{
        components.push_back( component );
}

void
UI::addButton( int x, int y, int w, int h, string text, Action* action )
{
        Button* button = new Button( x, y, w, h, 32, text, action );
        addComponent( button );

        MouseHoverSubscriber* mouseHoverSubscriber = new MouseHoverSubscriber( *button );
        mouseHoverPublisher->registerSubscriber( *mouseHoverSubscriber );

        MouseClickSubscriber* mouseClickSubscriber = new MouseClickSubscriber( *button );
        mouseClickPublisher->registerSubscriber( *mouseClickSubscriber );
}

void
UI::addBoard()
{
        board = new Board();
        addComponent( board );
}

void
UI::resetBoard()
{
        board->reset();
}

void
UI::addSelectorPanel()
{
        SelectorPanel* selectorPanel = new SelectorPanel();
        addComponent( selectorPanel );
}

void
UI::addSolvedMessage()
{
        Label*  solvedLabel = new Label( 800, 325, "Puzzle Solved!", 24, "white" );
        addComponent( solvedLabel );
}

void
UI::undoMove()
{
        vector< int > lastMove = sudokuGame->undoCellMove();

        if ( lastMove.size() == 0 )
        {
                return;
        }

        board->undoMove( lastMove );
}

UI::UI()
{
        mouseHoverPublisher = new UIEventPublisher< pair< int, int > >();
        mouseClickPublisher = new UIEventPublisher< SDL_Event >();

        addButton( 640, 550, 190, 60, "new game", ( new NewGameAction() ) );
        addButton( 1000, 550, 120, 60, "quit", ( new QuitGameAction() ) );
        addButton( 640, 400, 120, 60, "undo", ( new UndoMoveAction() ) );
        addButton( 1000, 400, 120, 60, "solve", ( NULL ) );

        addBoard();
        addSelectorPanel();
}

UI::~UI()
{
        for ( auto component : components )
        {
                delete component;
        }
        delete mouseHoverPublisher;
        delete mouseClickPublisher;
}

void
UI::update( SDL_Event event )
{
        if ( event.type == SDL_MOUSEMOTION )
        {
                int mouse_x = 0;
                int mouse_y = 0;
                SDL_GetMouseState( &mouse_x, &mouse_y );
                mouseHoverPublisher->publishData( std::make_pair( mouse_x, mouse_y ) );
        }
        if ( event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP )
        {
                mouseClickPublisher->publishData( event );
        }
}

void
UI::render()
{
        for ( auto component : components )
        {
                component->render();
        }
}

UIEventPublisher< pair< int, int > >*
UI::getMouseHoverPublisher()
{
        return mouseHoverPublisher;
}

UIEventPublisher< SDL_Event >*
UI::getMouseClickPublisher()
{
        return mouseClickPublisher;
}
