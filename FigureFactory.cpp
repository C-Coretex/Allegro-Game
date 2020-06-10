#include "FigureFactory.h"
#include "Figure.h"
#include "Circle.h"
#include "Square.h"
#include <cstdlib>
#include <iostream>

Figure *FigureFactory::Create( Type type)
{
    switch( type )
    {
        case RandomCircle:
            return new Circle( 10.0 + rand() % 30, 150, 150, 150);
        case RandomSquare:
            return new Square( 10.0 + rand() % 30, 0, 100, 200 );
    }
}


Figure *FigureFactory::Deserialize(string object)
{
    getline(std::cin, object);

    string sub = object.substr(0, object.find(":"));
    if(sub == "Square")
    {
        Square *sq = new Square( 10.0 + rand() % 30, 0, 100, 200 );
        sq->Deserialize(object);
        return sq;
    }
    else if(sub == "Circle")
    {
        Circle *cr = new Circle( 10.0 + rand() % 30, 150, 150, 150);
        cr->Deserialize(object);
        return cr;
    }
}
