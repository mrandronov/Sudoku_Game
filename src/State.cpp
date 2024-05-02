#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "SDL2/SDL.h"

#include "State.h"

SudokuGame* sudokuGame;
State::State()
{
        window = new Window();
        theme = new Theme( theme_path );
}

State::~State()
{
        delete ui;
        delete sudokuGame;
        delete theme;
        delete window;
}

void
State::initialize()
{
        // Slapping a random puzzle selector on startup.
        srand( time( NULL ) );
        int puzzleNum = rand() % 99 + 1;
        string new_puzzle_path = "./SudokuPuzzles/puzzle" + to_string( puzzleNum ) + ".sp";

        sudokuGame = new SudokuGame( new_puzzle_path );
        ui = new UI();
}

void
State::quitApplication()
{
        window->quit();
}

void
State::newPuzzle()
{
        sudokuGame->reset( puzzle_path );
        ui->resetBoard();
}

SDL_Renderer*
State::getRenderer()
{
        return window->getRenderer();
}

string
State::getFontPath()
{
        return font_path;
}
