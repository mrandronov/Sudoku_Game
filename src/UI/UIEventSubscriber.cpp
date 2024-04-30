
#include <iostream>

#include "UIEventSubscriber.h"

using namespace std;

SelectorPanelClickSubscriber::SelectorPanelClickSubscriber( Component& parent, Component& comp ) : parent( &parent )
{
        this->comp = &comp;
}

void
SelectorPanelClickSubscriber::recvPublishedData( SDL_Event data )
{
        SDL_Event event = data;

        if ( !comp->isMouseOver() )
        {
                return;
        }

        if ( event.type == SDL_MOUSEBUTTONDOWN )
        {
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                        if ( !comp->isClick )
                        {
                                parent->clickUpdate();
                        }
                        comp->onClick();
                }
        }
        if ( event.type == SDL_MOUSEBUTTONUP )
        {
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                        comp->clickUpdate();
                }
        }
}

MouseHoverSubscriber::MouseHoverSubscriber( Component& comp )
{
        this->comp = &comp;
}

void
MouseHoverSubscriber::recvPublishedData( pair< int, int > data )
{
        if ( comp->isMouseOver( get< 0 >( data ), get< 1 >( data ) ) )
        {
                comp->isHover = true;
        }
        else
        {
                comp->isHover = false;
        }
}

MouseClickSubscriber::MouseClickSubscriber( Component& comp )
{
        this->comp = &comp;
}

void
MouseClickSubscriber::recvPublishedData( SDL_Event data )
{
        SDL_Event event = data;

        if ( !comp->isMouseOver() )
        {
                return;
        }

        if ( event.type == SDL_MOUSEBUTTONDOWN )
        {
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                        comp->onClick();
                }
        }
        if ( event.type == SDL_MOUSEBUTTONUP )
        {
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                        comp->clickUpdate();
                }
        }
}

template< typename T >
UIEventSubscriber< T >::UIEventSubscriber( Component& comp )
{
        this->comp = &comp;
}

template< typename T >
void
UIEventSubscriber< T >::recvPublishedData( T data )
{
        if ( this->comp->isMouseOver( get< 0 >( data ), get< 1 >( data ) ) )
        {
                this->comp->isHover = true;
        }
        else
        {
                this->comp->isHover = false;
        }
}
template class UIEventSubscriber< pair< int, int > >;
