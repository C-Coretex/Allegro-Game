#pragma once
#include "ISerializable.h"

class Figure: ISerializable
{
    public:
        Figure(int SCREEN_W_, int SCREEN_H_);
        virtual ~Figure();
        void Reset();
        virtual void Draw() = 0;
        virtual void Move();
            int SCREEN_W;
            int SCREEN_H;
            double x_;
            double y_;
            double dx_;
            double dy_;
            int safeSpace;

        virtual string Serialize() = 0;
        virtual void Deserialize(string object) = 0;
    protected:

    private:
};
