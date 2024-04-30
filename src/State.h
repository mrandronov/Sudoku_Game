#ifndef __LIB_STATE_H__
#define __LIB_STATE_H__

#include <iostream>

#include "SDL2/SDL.h"

#include "UI/Theme.h"
#include "UI/UI.h"
#include "Window.h"
#include "game/SudokuGame.h"

using namespace std;

class State
{
        string                  theme_path = "./themes/Default.th";
        string                  font_path = "./fonts/GaruteBold-9YnYZ.ttf";
        string                  puzzle_path = "./SudokuPuzzles/puzzle10.sp";

        public:
                Window*                 window;
                Theme*                  theme;
                UI*                     ui;
                int                     inputNumber = -1;
                
                State();
                ~State();

                void                    initialize();
                void                    quitApplication();
                void                    newPuzzle();
                SDL_Renderer*           getRenderer();
                string                  getFontPath();
};

extern State* state;

#endif /* __LIB_STATE_H__ */