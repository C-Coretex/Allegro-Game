#pragma once
#include "Figure.h"
#include "ISerializable.h"

class Square: public Figure, public ISerializable
{
protected:
    double a_;
    unsigned char color_R;
    unsigned char color_G;
    unsigned char color_B;
public:
    Square( double a, unsigned char R, unsigned char G, unsigned char B);
    virtual void Draw();
    virtual ~Square();

    virtual string Serialize();
    virtual void Deserialize(string object);
private:
    int temp;
};
