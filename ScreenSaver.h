#pragma once
#include "Figure.h"
#include <vector>

class ScreenSaver
{
    public:
        static ScreenSaver &Instance();
        void Draw();
        void Next();
        void Add( Figure *f );
        void Reset();
        void ClearAll();
        typedef Figure * PFigure;
        vector<PFigure> figures;
    protected:

    private:
        ScreenSaver();
        virtual ~ScreenSaver();
        vector <PFigure>::iterator it;
};
