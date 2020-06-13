#include "ScreenSaver.h"
#include "Figure.h"
#include "AllegroBase.hpp"
#include "AlegroApp.h"
#include <vector>
#include <iostream>
#include <unistd.h>

ScreenSaver &ScreenSaver::Instance()
{
    static ScreenSaver instance;
    return instance;
}

ScreenSaver::ScreenSaver(){}

ScreenSaver::~ScreenSaver()
{
    for(it = figures.begin(); it != figures.end(); ++it)
    {
        delete *it;
    }
    figures.clear();
}

void ScreenSaver::Draw()
{
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
    for(it = figures.begin(); it != figures.end(); ++it)
    {
        (*it)->Draw();
    }
}

void ScreenSaver::Next()
{
    for(it = figures.begin(); it != figures.end(); ++it)
    {
        (*it)->Move();
        for(vector <PFigure>::iterator it2 = figures.begin(); it2 != figures.end(); ++it2)
        {

            if(*it2 == *it)
            {
                continue;
            }

            if(**it == **it2)
            {
                int tempDX = (*it)->dx_;
                int tempDY = (*it)->dy_;

                (*it)->dx_ = (*it2)->dx_;
                (*it)->dy_ = (*it2)->dy_;
                (*it2)->dx_ = tempDX;
                (*it2)->dy_ = tempDY;
            }
        }
    }
}

void ScreenSaver::Add( Figure *f )
{
    figures.push_back(f);
}

void ScreenSaver::Reset()
{
    for(it = figures.begin(); it != figures.end(); ++it)
    {
        (*it)->Reset();
    }
    AlegroApp::dash = 20;
}

void ScreenSaver::ClearAll()
{
    for(it = figures.begin(); it != figures.end(); ++it)
    {
        (*it)->~Figure();
    }
    AlegroApp::dash = 20;
    figures.clear();
}
