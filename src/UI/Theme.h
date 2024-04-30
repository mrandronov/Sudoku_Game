#ifndef __LIB_COLOR_SET_H__
#define __LIB_COLOR_SET_H__

#include <iostream>
#include <map>

#include "SDL2/SDL.h"
#include "Color.h"

class Theme
{
        protected:
                std::map< std::string, Color > colorSet;

        public:
                Theme( std::string themePath );
                
                void            setColor( SDL_Renderer* renderer, std::string name );
                SDL_Color*      getColor( std::string name );

};

#endif /* __LIB_COLOR_SET_H__ */
