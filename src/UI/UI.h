#ifndef __LIB_UI_H__
#define __LIB_UI_H__

#include <iostream>
#include <vector>

#include "SDL2/SDL.h"

#include "UIEventSubscriber.h"
#include "Action.h"

using namespace std;

template< typename T >
class UIEventPublisher
{
        private:
                vector< SubscriberIf< T >* >    subscribers;

        public:
                void    registerSubscriber( SubscriberIf< T >& subscriber );
                void    deleteSubscriber( SubscriberIf< T >& subscriber ); 
                void    publishData( T data );
};

template< typename T >
class UIComponent
{
        T               component;
        bool            enabled;

        public:
                void render();
};

class UI
{
        vector< Component* >                            components;

        public:
                UI();
                ~UI();

                void    addComponent( Component* ptr );
                void    addButton( int x, int y, int w, int h, string text, Action* action );
                void    addBoard();
                void    resetBoard();
                void    addSelectorPanel();
                void    addSolvedMessage();
                void    undoMove();
                void    update( SDL_Event event );
                void    render();
                UIEventPublisher< pair< int, int > >* getMouseHoverPublisher();
                UIEventPublisher< SDL_Event >* getMouseClickPublisher();
};

extern UIEventPublisher< pair< int, int > >*            mouseHoverPublisher;
extern UIEventPublisher< SDL_Event >*                   mouseClickPublisher;

#endif /* __LIB_UI_H__ */