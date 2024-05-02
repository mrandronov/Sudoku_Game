
#include <iostream>

#include "Action.h"
#include "Component/Board.h"

using namespace std;

int NewGameAction::action()
{
        cout << "New Game!\n";
        return 0;
}

int QuitGameAction::action()
{
        cout << "Quit Game!\n";
        state->quitApplication();
        return 0;
}

NumberSelectAction::NumberSelectAction( int number )
{
        this->selectedNumber = number;
}

int NumberSelectAction::action()
{
        state->inputNumber = selectedNumber;
        board->setHighlightCells( true, selectedNumber );

        return 0;
}

UndoMoveAction::UndoMoveAction() {}

int UndoMoveAction::action()
{
        state->ui->undoMove();

        return 0;
}