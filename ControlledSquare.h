#pragma once
#include "Square.h"

class ControlledSquare : public Square
{
    public:
        ControlledSquare( double side );
        void MoveBy( double dx, double dy );
        virtual void Draw(int origDash, int curDash);
        virtual ~ControlledSquare();
    protected:

    private:
};
