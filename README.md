# Sudoku_Game

- [Explanation](#explanation)
- [Building](#building)
- [Execution](#execution)
- [Todo](#todo)

This project implements an Sudoku puzzle application in C++ using SDL. The game is a simple point in click, there are no points or rewards other than a 'Puzzle Solved!' message when you have completed a puzzle. I've included 99 sudoku puzzles I found off of kaggle. I have a csv when about 100,000 I believe however I figured 99 is good enough.

I reuse the theming technique and the overall code design of my Tic-Tac-Toe project now implemented in C++. The support for object oriented programming did help in structuring the code and made referencing certain objects easier. I now know of a few better ways to implement what I did in the Tic-Tac-Toe in C, but doing this project in C++ gave me a referesher on OOP which I found was quite helpful.

## Building

Make sure you have SDL2 and SDL2_ttf libraries installed. This repo does not come with those.

So far as I know, cmake should run on at least linux with the current `CMakeLists.txt`, but I didn't test this on a linux machine so I'm not sure. Windows users beware.

To build, simply run:
```
mkdir build && cd build && cmake .. && make
```

I included a `justfile`. If you have the `Just` command line runner installed, you can just execute `just run` and this will build and start your application.

Included in the just file are the follow commands:
- `just build` - Simply build the application and do nothing else.
- `just exec` - Just execute the application.
- `just run` - Build **and** run the application.
- `just clean` - Clean the build directory, if it exists.
- `just new` - Cleans the build directory, if it exists, then builds and runs the application.

## Execution

Just run `./build/SudokuApp` from your build folder after building the application. Alternatively, use the just file as mentioned above.

## Todo

The current state of the game is quite playable, however in the ( near ) future, I hope to implement 
- [ ] The puzzle solving mechanism 
- [ ] Better cell highlighting
- [ ] Be able to switch puzzles without restarting the application ( The 'new game' button has been tough to iron out ).
- [ ] This whole project probably needs better error handling.
