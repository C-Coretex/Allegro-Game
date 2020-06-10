#include "Figure.h"
#include <stdlib.h>

Figure::Figure(int SCREEN_W_, int SCREEN_H_):
    SCREEN_W(SCREEN_W_),
    SCREEN_H(SCREEN_H_)
{
    Reset();
}

Figure::~Figure(){};

void Figure::Reset()
{
    x_ = rand() % SCREEN_W;
    y_ = rand() % SCREEN_H;
    dx_ = 10.0 - rand() % 21;
    dy_ = 10.0 - rand() % 21;
}

void Figure::Move()
{
    x_ += dx_;
    y_ += dy_;
    if ( ( x_ - safeSpace < 1.0 ) || ( x_ + safeSpace > SCREEN_W ) )
        dx_ *= -1;
    if( (y_ + safeSpace < 1.0 ) || ( y_ - safeSpace > SCREEN_H ) )
        dy_ *= -1;
}
