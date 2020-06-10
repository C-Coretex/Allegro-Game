#include "Circle.h"
#include "Figure.h"
#include <stdlib.h>
#include "AllegroBase.hpp"

Circle::Circle( double r, unsigned char R, unsigned char G, unsigned char B) :
        Figure(1200, 1000),
        r_( r ),
        color_R( R ),
        color_G( G ),
        color_B( B )
{
    safeSpace = r_;
    temp = 1;
}

void Circle::Draw()
{
    if(color_G >= 250 || color_G <= 100)
        temp *= -1;
    color_G += temp;
    al_draw_filled_circle( x_, y_, r_, al_map_rgb( color_R, color_G, color_B ) );
}

string Circle::Serialize()
{
    string object = "Circle:";
    object+= "x=" + to_string(x_) + ";";
    object+= "y=" + to_string(y_) + ";";
    object+= "side=" + to_string(r_) + ";";

    return object;
}

void Circle::Deserialize(string object)
{
    string sub;

    sub = object.substr(object.find("=")+1, object.find(";"));
    object = object.substr(object.find(";")+1, object.length());
    x_ = atof(sub.c_str());

    sub = object.substr(object.find("=")+1, object.find(";"));
    object = object.substr(object.find(";")+1, object.length());
    y_ = atof(sub.c_str());

    sub = object.substr(object.find("=")+1, object.find(";"));
    object = object.substr(object.find(";")+1, object.length());
    r_ = atoi(sub.c_str());

    safeSpace = r_/2;
}

Circle::~Circle(){}
