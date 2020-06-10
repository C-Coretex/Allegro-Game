#include "AlegroApp.h"
#include "AllegroBase.hpp"
#include "ScreenSaver.h"
#include "SizeableSquare.h"
#include "FigureFactory.h"
#include <iostream>
#include <list>

AlegroApp::AlegroApp() :
    AllegroBase(),
    humanSquare_( 50 )
{
    for( int i = 0; i < MAX-3; ++i )
    {
        if ( ( i % 2 ) == 0 )
        {
            ScreenSaver::Instance().Add(
                FigureFactory::Create( FigureFactory::RandomSquare) );
        }
        else
        {
            ScreenSaver::Instance().Add(
                FigureFactory::Create( FigureFactory::RandomCircle ) );
        }
    }
    for(int i = 0; i < 3; ++i)
    {
        ScreenSaver::Instance().Add( new SizeableSquare( 10.0 + rand() % 30 ) );
    }
}

int AlegroApp::dash = 20;

AlegroApp::~AlegroApp()
{}

list <Figure*>::iterator it;

void AlegroApp::Fps()
{
    ScreenSaver::Instance().Next();

    for(it = ScreenSaver::Instance().figures.begin(); it != ScreenSaver::Instance().figures.end(); ++it)
        if(((abs((*it)->x_ - humanSquare_.x_) <= (*it)->safeSpace + humanSquare_.safeSpace)
            && abs((*it)->y_ - humanSquare_.y_) <= (*it)->safeSpace + humanSquare_.safeSpace))
            ScreenSaver::Instance().Reset();

    double dx = 0, dy = 0;
    if ( IsPressed( ALLEGRO_KEY_UP ) )
    {
        dy = -5;
    }
    if ( IsPressed( ALLEGRO_KEY_DOWN ) )
    {
        dy = +5;
    }
    if ( IsPressed( ALLEGRO_KEY_LEFT ) )
    {
        dx = -5;
    }
    if ( IsPressed( ALLEGRO_KEY_RIGHT ) )
    {
        dx = +5;
    }
    if ( IsPressed( ALLEGRO_KEY_LSHIFT ) )
    {
        if(!(dash <= 0))
        {
            --dash;
            dy *= 5;
            dx *= 5;
        }
    }
    humanSquare_.MoveBy( dx, dy );
}

void AlegroApp::Draw()
{
    ScreenSaver::Instance().Draw();
    humanSquare_.Draw(20, dash);
}

void AlegroApp::OnKeyDown( const ALLEGRO_KEYBOARD_EVENT &keyboard )
{
    if ( keyboard.keycode == ALLEGRO_KEY_SPACE )
    {
        ScreenSaver::Instance().Reset();
    }
    else if ( keyboard.keycode == ALLEGRO_KEY_ESCAPE )
    {
        Exit();
    }
    else if ( keyboard.keycode == ALLEGRO_KEY_P )
    {
        for(it = ScreenSaver::Instance().figures.begin(); it != ScreenSaver::Instance().figures.end(); ++it)
        {
            cout << (*it)->Serialize() << endl;
        }
    }
    else if ( keyboard.keycode == ALLEGRO_KEY_ENTER )
    {
        string str;
        getline(std::cin, str);
        ScreenSaver::Instance().Add(FigureFactory::Deserialize(str));
    }
}
