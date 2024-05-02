
#include <iostream>

#include "SDL2/SDL.h"

#include "Label.h"

using namespace std;

Label::Label( int x, int y, string text, int size, string color )
{
        string          font_path = state->getFontPath();
        SDL_Renderer*   renderer = state->getRenderer();
        SDL_Color*      font_color = state->theme->getColor( color );

        TTF_Font* font = TTF_OpenFont( font_path.c_str(), size );
        assert_msg( (font == NULL), TTF_GetError() );

        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), *font_color );
        assert_msg( (surface == NULL), TTF_GetError() );

        texture = SDL_CreateTextureFromSurface( renderer, surface );
        assert_msg( (texture == NULL), SDL_GetError() );

        box = ( SDL_Rect* ) malloc( sizeof( SDL_Rect ) );
        *box = ( SDL_Rect ) { .x = x, .y = y };

        assert_msg( ( SDL_QueryTexture( texture,
                                        NULL,
                                        NULL,
                                        &( box->w ), 
                                        &( box->h ) ) != 0 ),
                        SDL_GetError() );

        SDL_FreeSurface( surface );
        TTF_CloseFont( font );
}

Label::~Label()
{
        SDL_DestroyTexture( texture );

        free( box );
}

void
Label::render()
{
        SDL_RenderCopy( state->getRenderer(), texture, NULL, box );
}

void
Label::center( int parent_w, int parent_h )
{
        int cur_w = box->w;
        int cur_h = box->h;

        int padding_x = ( parent_w - cur_w ) / 2;
        int padding_y = ( parent_h - cur_h ) / 2;

        box->x += padding_x;
        box->y += padding_y;
}

void
Label::onClick()
{

}

void
Label::clickUpdate()
{

}
