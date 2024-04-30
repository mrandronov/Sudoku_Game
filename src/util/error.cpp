#include <iostream>

#include "error.h"

void
assert_msg( int condition, const std::string msg )
{
        if ( !condition )
        {
                return;
        }

        std::cerr << "Error: " << msg << "\n";
        exit( 1 );
}
