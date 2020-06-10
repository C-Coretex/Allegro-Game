#pragma once
#include <string>

using namespace std;
class ISerializable
{
    public:
        virtual string Serialize() = 0;
        virtual void Deserialize(string object) = 0;

    protected:

    private:
};

