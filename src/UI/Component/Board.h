#ifndef __LIB_BOARD_H__
#define __LIB_BOARD_H__

#include <iostream>

#include "Cell.h"

using namespace std;

#define BOARD_START_X 40
#define BOARD_START_Y 70

class Board : public Component
{
        vector< vector< Cell* > >       cells;
        vector< vector< MouseHoverSubscriber* > > cellMouseHoverSubscribers;
        vector< vector< MouseClickSubscriber* > > cellMouseClickSubscribers;

        public:
                Board();
                ~Board();

                void            addCell( int x, int y, int r, int c );
                void            addCells();
                void            drawGridLine( Cell* start, Cell* end, string color, bool isVertical );
                void            undoMove( vector< int > lastMove );
                void            setHighlightCells( bool isHighlighted = false, int val = 0 );
                void            reset();

                virtual void    render()        override;
                virtual void    onClick()       override;
                virtual void    clickUpdate()   override;
};

extern Board* board;

#endif /* __LIB_BOARD_H__ */