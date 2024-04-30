#ifndef __LIB_UI_EVENT_SUBSCRIBER_H__
#define __LIB_UI_EVENT_SUBSCRIBER_H__

#include <iostream>

#include "Component/Component.h"

using namespace std;

template< typename T >
class SubscriberIf {
        public:
                Component* comp;
                virtual void    recvPublishedData( T data ) = 0;
                bool            operator==( const SubscriberIf< T > other ) const;
};

class SelectorPanelClickSubscriber : public SubscriberIf< SDL_Event >
{
        Component*      parent;
        public:
                SelectorPanelClickSubscriber( Component& parent, Component& comp );

                virtual void recvPublishedData( SDL_Event data  ) override;
};

class MouseHoverSubscriber : public SubscriberIf< pair< int, int > >
{
        public:
                MouseHoverSubscriber( Component& comp );

                virtual void recvPublishedData( pair< int, int > data ) override;
};

class MouseClickSubscriber : public SubscriberIf< SDL_Event >
{
        public:
                MouseClickSubscriber( Component& comp );

                virtual void recvPublishedData( SDL_Event data ) override;
};

template< typename T >
class UIEventSubscriber : public SubscriberIf< T >
{
        public:
                UIEventSubscriber( Component& comp );

                virtual void recvPublishedData( T data ) override;
};

#endif /* __LIB_UI_EVENT_SUBSCRIBER_H__ */