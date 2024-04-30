#ifndef __LIB_WINDOW_H__
#define __LIB_WINDOW_H__

#include <iostream>

#include "SDL2/SDL.h"

#include "util/error.h"

using namespace std;

class Window
{
        protected:
                string                  TITLE = "Sudoku App";
                int                     SCREEN_WIDTH = 1200;
                int                     SCREEN_HEIGHT = 700;
                
                float                   fps_cap = 60.0f;
                float                   fps_cap_in_ms = 1000.0f / fps_cap;
                uint64_t                start_time;
                uint64_t                end_time;
                float                   delta;

                bool                    isAppRunning = true;

                SDL_Window*             window;
                SDL_Renderer*           renderer;

        public:
                Window();
                ~Window();

                void                    update();
                void                    clearScreen();
                void                    display();
                void                    render();
                void                    windowLoop();
                SDL_Renderer*           getRenderer();
                void                    quit();

};

#endif /* __LIB_WINDOW_H__ */