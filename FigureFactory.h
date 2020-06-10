#pragma once
#include "Figure.h"

class FigureFactory
{
    public:
        enum Type
        {
            RandomCircle,
            RandomSquare
        };

    static Figure * Create( Type type);
    static Figure *Deserialize(string object);
    protected:

    private:
};
