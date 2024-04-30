#ifndef __LIB_BUTTON_H__
#define __LIB_BUTTON_H__

#include <iostream>

#include "SDL2/SDL.h"

#include "Component.h"
#include "Label.h"
#include "../Action.h"

using namespace std;

class Button : public Component
{
        public:
                Label*          label;
                Action*         action;

                Button( int x, int y, int w, int h, string text, Action *action );
                Button( int x, int y, int w, int h, int size, string text, Action *action );

                virtual void    render()        override;
                virtual void    onClick()       override;
                virtual void    clickUpdate()   override;
};

class Selector : public Button
{
        bool    isSelected;

        public:
                Selector( int x, int y, int w, int h, string text, Action *action );

                void            deselect();

                virtual void    render()        override;
                virtual void    onClick()       override;
                virtual void    clickUpdate()   override;
};

#endif /* __LIB_BUTTON_H__ */