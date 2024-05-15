#ifndef __LIB_COMPONENT_H__
#define __LIB_COMPONENT_H__

#include <iostream>

#include "SDL2/SDL.h"

class Component {
        public:
                SDL_Rect*               box;
                bool                    isHover = false;
                bool                    isClick = false;
                bool                    isEnabled = true;

                Component();
                virtual                 ~Component();

                bool                    isMouseOver( int mouse_x, int mouse_y );
                bool                    isMouseOver();
                void                    onHover();

                virtual void            render()        = 0;
                virtual void            onClick()       = 0;
                virtual void            clickUpdate()   = 0;
};

#endif /* __LIB_COMPONENT_H__ */
