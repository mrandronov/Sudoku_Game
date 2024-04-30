
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "SDL2/SDL.h"

#include "util/error.h"
#include "Color.h"
#include "Theme.h"

#define COLOR_SET_SIZE 9
#define NUM_THEME_COLORS 5

using namespace std;

vector< string > loadedColors;

std::vector< std::string > colorNames = { "clear",
                        "white",
                        "background",
                        "default_color",
                        "highlight_color",
                        "select_color",
                        "press_color",
                        "orange",
                        "green" };

int
hexToInt( string hexVal )
{
        unsigned        n;
        stringstream    ss;

        ss << hex << hexVal;
        ss >> n;
        
        return static_cast<int>( n );
}

std::vector< int > 
hexToColor( string hexVal )
{
        int             r = hexToInt( hexVal.substr( 0, 2 ) );
        int             g = hexToInt( hexVal.substr( 2, 2 ) );
        int             b = hexToInt( hexVal.substr( 4, 2 ) );

        std::vector< int > color( 4, 0 );
        color[ 0 ] = r;
        color[ 1 ] = g;
        color[ 2 ] = b;
        color[ 3 ] = 255;

        return color;
}

int
load_theme( string theme_path )
{
        string          line;
        fstream         file( theme_path );

        // Get name of theme and print to stdout.
        getline( file, line );
        cout << "Loading theme [ " << line << " ]...\n";

        // Get hex values of the theme colors.
        for ( int i = 0; i < NUM_THEME_COLORS; i++ )
        {
                getline( file, line );
                loadedColors.push_back( line );
        }

        file.close();

        return 0;
}

Theme::Theme( std::string theme_path )
{
        loadedColors.push_back( "000000" );
        loadedColors.push_back( "ffffff" );

        load_theme( theme_path );

        loadedColors.push_back( "883333" );
        loadedColors.push_back( "64c864" );

        for ( int i = 0; i < COLOR_SET_SIZE; i++ )
        {
                vector< int > col = hexToColor( loadedColors[ i ] );
                this->colorSet.insert( 
                        std::pair< std::string, Color > ( colorNames[ i ],
                                Color( col[ 0 ],
                                        col[ 1 ],
                                        col[ 2 ],
                                        col[ 3 ]
                                ) 
                        )
                );
                cout << "Loaded theme[ " << i << " ] = { " << loadedColors[ i ] << " }\n";
        }
}

SDL_Color*
Theme::getColor( std::string name )
{
        return colorSet.at( name ).getSDLColor();
}

void 
Theme::setColor( SDL_Renderer* renderer, std::string name )
{
        SDL_Color*      color = getColor( name );

        SDL_SetRenderDrawColor( renderer,
                                color->r,
                                color->g,
                                color->b,
                                color->a );
}

