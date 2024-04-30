#ifndef __LIB_SELECTOR_PANEL_H__
#define __LIB_SELECTOR_PANEL_H__

#include <iostream>

#include "Button.h"

using namespace std;

#define SELECTOR_SIZE 90
#define SPACING 17

class SelectorPanel : public Component
{
        vector< Selector* >                     selectors;

        public:
                SelectorPanel();

                void            addSelector( int x, int y, int i );
                void            disableAll();

                virtual void    render()        override;
                virtual void    onClick()       override;
                virtual void    clickUpdate()   override;

};

#endif /* __LIB_SELECTOR_PANEL_H__ */