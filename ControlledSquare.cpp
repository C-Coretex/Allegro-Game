#include "ControlledSquare.h"
#include "Square.h"
#include "AllegroBase.hpp"

ControlledSquare::ControlledSquare( double side ) :
    Square( side, 255, 255, 255 )
{}

void ControlledSquare::MoveBy( double dx, double dy )
{
    if(x_ + a_/2 + dx  >= 1200 || y_ + a_/2 + dy  >= 1000)
    {
        x_ -= 1;
        y_ -= 1;
        return;
    }
    if(x_ - a_/2 - dx <= 0 || y_ - a_/2 - dy <= 0)
    {
        x_ += 1;
        y_ += 1;
        return;
    }

    dx_ = dx;
    dy_ = dy;
    Move();
}

void ControlledSquare::Draw(int origDash, int curDash)
{
    double half = a_ / 2;
    al_draw_filled_rectangle( x_ - half, y_ - half,
        x_ + half, y_ + half, al_map_rgb( 255, 255, 255 ) );



    al_draw_filled_rectangle(x_ - half, y_ - half - 15, x_ + half, y_ - half - 5, al_map_rgb( 255, 0, 0 ));

    double size_ = (double)a_/origDash;
    double factor = size_ * curDash;

    al_draw_filled_rectangle(x_ - half, y_ - half - 15, x_ - half + factor, y_ - half - 5, al_map_rgb( 0, 255, 0 ));
}

ControlledSquare::~ControlledSquare()
{}
