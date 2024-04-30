
#include <iostream>

#include "SelectorPanel.h"
#include "Board.h"

using namespace std;

SelectorPanel::SelectorPanel()
{
        for( int i = 0; i < 5; i++ )
        {
                addSelector( 640 + i * ( SELECTOR_SIZE + SPACING ), 70, i + 1);
        }

        for( int i = 5; i < 9; i++ )
        {
                addSelector( 685 + ( i - 5 ) * ( SELECTOR_SIZE + SPACING ), 177, i + 1 );
        }
}

void
SelectorPanel::addSelector( int x, int y, int i )
{
        Selector* selector = new Selector( x, y, SELECTOR_SIZE, SELECTOR_SIZE, to_string( i ), ( new NumberSelectAction( i ) ) );
        selectors.push_back( selector );

        MouseHoverSubscriber* mouseHoverSubscriber = new MouseHoverSubscriber( *selector );
        mouseHoverPublisher->registerSubscriber( *mouseHoverSubscriber );

        SelectorPanelClickSubscriber* mouseClickSubscriber = new SelectorPanelClickSubscriber( *this, *selector );
        mouseClickPublisher->registerSubscriber( *mouseClickSubscriber );
}

void
SelectorPanel::disableAll()
{
        for ( auto selector : selectors )
        {
                selector->deselect();
        }
}

void
SelectorPanel::render()
{
        for ( auto selector : selectors )
        {
                selector->render();
        }
}

void
SelectorPanel::onClick()
{

}

void
SelectorPanel::clickUpdate()
{
        this->disableAll();
        board->setHighlightCells();
}

