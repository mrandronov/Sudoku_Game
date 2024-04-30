#ifndef __LIB_LABEL_H__
#define __LIB_LABEL_H__

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "Component.h"
#include "../../State.h"

using namespace std;

class Label : public Component
{
        public:
                string          text;
                int             size;
                SDL_Color*      color;
                SDL_Texture*    texture;

                Label( int x, int y, string text, int size, string color );
                ~Label();

                void center( int parent_w, int parent_h );

                virtual void    render()        override;
                virtual void    onClick()       override;
                virtual void    clickUpdate()   override;
};

#endif /* __LIB_LABEL_H__ */