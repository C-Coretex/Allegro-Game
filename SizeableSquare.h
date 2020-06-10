#pragma once
#include "SizeableFigure.h"
#include "Square.h"

class SizeableSquare: public SizeableFigure, public Square
{
    public:
        SizeableSquare(int a);
        virtual ~SizeableSquare();
        void virtual Move();
    protected:

    private:
        int sizeChanger = 5;
};
