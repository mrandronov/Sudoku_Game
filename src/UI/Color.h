#ifndef __LIB_COLOR_H__
#define __LIB_COLOR_H__

#include "SDL2/SDL.h"

class Color
{
        SDL_Color*      color_sdl;

        public:
                Color( int r, int g, int b, int a );

                SDL_Color* getSDLColor();
};

#endif /* __LIB_COLOR_H__ */
