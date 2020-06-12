#include "Square.h"
#include "Figure.h"
#include "AllegroBase.hpp"
#include <iostream>

Square::Square( double a, unsigned char R, unsigned char G, unsigned char B) :
        Figure(1200, 1000),
        a_( a ),
        color_R( R ),
        color_G( G ),
        color_B( B )
    {
        safeSpace = a_/2;
    }

void Square::Draw()
{
    double half = a_ / 2;
    al_draw_filled_rectangle( x_ - half, y_ - half,
        x_ + half, y_ + half, al_map_rgb( color_R, color_G, color_B ) );
}

string Square::Serialize()
{
    string object = "Square:";
    object+= "x=" + to_string(x_) + ";";
    object+= "y=" + to_string(y_) + ";";
    object+= "side=" + to_string(a_) + ";";
    object+= "dx=" + to_string(dx_) + ";";
    object+= "dy=" + to_string(dy_) + ";";

    return object;
}

void Square::Deserialize(string object)
{
    try
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
        a_ = atoi(sub.c_str());

        sub = object.substr(object.find("=")+1, object.find(";"));
        object = object.substr(object.find(";")+1, object.length());
        dx_ = atoi(sub.c_str());

        sub = object.substr(object.find("=")+1, object.find(";"));
        object = object.substr(object.find(";")+1, object.length());
        dy_ = atoi(sub.c_str());

        safeSpace = a_/2;
    }
    catch(exception ex)
    {
        cout << "Ti sto sdelal-_-" << endl;
    }
}

Square::~Square(){}
