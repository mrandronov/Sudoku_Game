
#include <iostream>

#include "SDL2/SDL.h"

#include "Color.h"

Color::Color( int r, int g, int b, int a )
{
        this->color_sdl = ( SDL_Color* ) malloc( sizeof( SDL_Color ) );

        *(this->color_sdl) = ( SDL_Color ) { 
                .r = static_cast< Uint8 > (r), 
                .g = static_cast< Uint8 > (g),
                .b = static_cast< Uint8 > (b), 
                .a = static_cast< Uint8 > (a) };
}

SDL_Color*
Color::getSDLColor()
{
        return this->color_sdl;
}

