
#include "Component.h"

Component::Component()
{

}

Component::~Component()
{
}

bool
Component::isMouseOver( int mouse_x, int mouse_y )
{
        if ( mouse_x > box->x && mouse_x < box->x + box->w && 
                mouse_y > box->y && mouse_y < box->y + box->h )
        {
                return true;
        }
        return false;
}

bool
Component::isMouseOver( )
{
        int mouse_x;
        int mouse_y;
        SDL_GetMouseState( &mouse_x, &mouse_y );
        if ( mouse_x > box->x && mouse_x < box->x + box->w && 
                mouse_y > box->y && mouse_y < box->y + box->h )
        {
                return true;
        }
        return false;
}

void
Component::onHover()
{
        isHover = true;
}

void
Component::onClick()
{

}
