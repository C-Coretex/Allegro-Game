#pragma once
#include "AllegroBase.hpp"
#include "ControlledSquare.h"

class AlegroApp: public AllegroBase
{
    public:
        static const int MAX = 10;
        AlegroApp();
        virtual ~AlegroApp();

        virtual void Fps();
        virtual void Draw();
        virtual void OnKeyDown( const ALLEGRO_KEYBOARD_EVENT &keyboard );

        static int dash;
    protected:

    private:
        ControlledSquare humanSquare_;
};

