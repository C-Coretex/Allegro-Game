#pragma once

class ISerializable
{
    public:
        virtual string Serialize() = 0;
        virtual void Deserialize(string object) = 0;
    protected:

    private:
};
