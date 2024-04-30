
#include "State.h"

State*  state;

int
main( int argc, char** argv )
{
        state = new State();

        state->initialize();
        state->window->windowLoop();

        delete state;

        return 0;
}
