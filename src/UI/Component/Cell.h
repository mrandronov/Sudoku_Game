#ifndef __LIB_CELL_H__
#define __LIB_CELL_H__

#include "SDL2/SDL.h"

#include "Label.h"
#include "Component.h"

#define CELL_SIZE 60

class Cell : public Component
{
        Label*          label;
        int             row;
        int             col;

        public:
                int             val;
                bool            isHighlighted;

                Cell( int x, int y, int w, int h, int val, bool isEnabled );
                ~Cell();

                void            update( int val );

                virtual void    render()        override;
                virtual void    onClick()       override;
                virtual void    clickUpdate()   override;
};

#endif /* __LIB_CELL_H__ */