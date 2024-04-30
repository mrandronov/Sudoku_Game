
cmake_minimum_required( VERSION 3.9 )
set (CMAKE_CXX_STANDARD 20)

project( GUITest VERSION 1.0.0 DESCRIPTION "Sudoku App" )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src/ )

set( SOURCES 
        ./src/util/error.cpp
        ./src/game/SudokuGame.cpp
        ./src/UI/Component/Component.cpp
        ./src/UI/Component/Label.cpp
        ./src/UI/Component/Cell.cpp
        ./src/UI/Component/SelectorPanel.cpp
        ./src/UI/Component/Board.cpp
        ./src/UI/Component/Button.cpp
        ./src/UI/Color.cpp
        ./src/UI/Theme.cpp
        ./src/UI/Action.cpp
        ./src/UI/UIEventSubscriber.cpp
        ./src/UI/UI.cpp
        ./src/Window.cpp
        ./src/State.cpp
        ./src/main.cpp
)

set( HEADERS
        ./src/util/error.h
        ./src/game/SudokuGame.h
        ./src/UI/Component/Component.h
        ./src/UI/Component/Label.h
        ./src/UI/Component/Cell.h
        ./src/UI/Component/SelectorPanel.h
        ./src/UI/Component/Board.h
        ./src/UI/Component/Label.h
        ./src/UI/Component/Button.h
        ./src/UI/Color.h
        ./src/UI/Theme.h
        ./src/UI/Action.h
        ./src/UI/UIEventSubscriber.h
        ./src/UI/UI.h
        ./src/Window.h
        ./src/State.h
)

add_executable( GUITest ${SOURCES} ${HEADERS} )

find_package( SDL2 REQUIRED )
target_link_libraries( GUITest SDL2::SDL2 SDL2::SDL2main )

find_package( SDL2_ttf REQUIRED )
target_link_libraries( GUITest SDL2_ttf::SDL2_ttf )
