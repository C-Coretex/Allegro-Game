#pragma once
#include "Figure.h"
#include "ISerializable.h"

class Circle: public Figure, public ISerializable
{
protected:
    double r_;
    unsigned char color_R;
    unsigned char color_G;
    unsigned char color_B;
public:
    Circle( double r, unsigned char R, unsigned char G, unsigned char B);
    virtual void Draw();
    virtual ~Circle();

    virtual string Serialize();
    virtual void Deserialize(string object);
private:
    int temp;
};
