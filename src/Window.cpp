
#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "Window.h"
#include "State.h"

Window::Window()
{
        assert_msg( ( SDL_Init( SDL_INIT_VIDEO ) != 0 ), "SDL failed to initialize!" );

        window = SDL_CreateWindow( TITLE.c_str(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN );
        assert_msg( ( window == NULL ), "Window failed to initialize!" );

        renderer = SDL_CreateRenderer( window,
                        -1,
                        SDL_RENDERER_ACCELERATED );
        assert_msg( ( renderer == NULL ), "Renderer failed to initialize!" );

        assert_msg( ( TTF_Init() != 0 ), TTF_GetError() );

}

Window::~Window()
{
        SDL_DestroyRenderer( renderer );
        SDL_DestroyWindow( window );
}

void
Window::update()
{
        SDL_Event event;
        while( SDL_PollEvent( &event ) )
        {
                // Any events that can quit the application are 
                // handled here in the Window class.
                if ( event.type == SDL_QUIT )
                {
                        isAppRunning = false;
                }
                if ( event.type == SDL_KEYDOWN )
                {
                        if ( event.key.keysym.scancode == SDL_SCANCODE_Q )
                        {
                                isAppRunning = false;
                        }
                }

                // All other events are handled by the UI.
                state->ui->update( event );
        }
}

void
Window::clearScreen()
{
        state->theme->setColor( renderer, "clear" );
        SDL_RenderClear( renderer );
}

void
Window::display()
{
        SDL_RenderPresent( renderer );
}

void
Window::render()
{
        // clear the screen
        state->theme->setColor( renderer, "background" );
        SDL_RenderClear( renderer );

        state->ui->render();

        // render to display
        SDL_RenderPresent( renderer );
}

void
Window::windowLoop()
{
        while ( isAppRunning )
        {
                start_time = SDL_GetPerformanceCounter();

                update();
                render();

                // Fix the framerate to 60 frames per second
                end_time = SDL_GetPerformanceCounter();
                delta = ( end_time - start_time ) / ( float ) SDL_GetPerformanceFrequency() * 1000.0f;
                if ( delta < fps_cap_in_ms )
                {
                        SDL_Delay( fps_cap_in_ms - delta );
                }
        }
}

SDL_Renderer*
Window::getRenderer()
{
        return renderer;
}

void
Window::quit()
{
        isAppRunning = false;
}
