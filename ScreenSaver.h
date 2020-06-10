#pragma once
#include "Figure.h"
#include <list>

class ScreenSaver
{
    public:
        static ScreenSaver &Instance();
        void Draw();
        void Next();
        void Add( Figure *f );
        void Reset();
        typedef Figure * PFigure;
        list<PFigure> figures;
    protected:

    private:
        ScreenSaver();
        virtual ~ScreenSaver();
        list <PFigure>::iterator it;
};
