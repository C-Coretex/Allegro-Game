#include "SizeableSquare.h"
#include "Square.h"

SizeableSquare::SizeableSquare(int a):
    Square(a, 255, 0, 0)
{}

SizeableSquare::~SizeableSquare()
{}

void SizeableSquare::Move()
{
    if(a_ > 150 || a_ < 5)
        sizeChanger *= -1;
    a_ += sizeChanger;
    safeSpace = a_;
}
