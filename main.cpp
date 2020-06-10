#include <iostream>
#include "AlegroApp.h"

using namespace std;

const int FPS = 60;
const int SCREEN_W = 1200;
const int SCREEN_H = 1000;

int main(int argc, char **argv)
{
    srand( time(0) );
    AlegroApp app;
    if ( !app.Init( SCREEN_W, SCREEN_H, FPS ) )
    {
        return 1;
    }
    app.Run();

    // cin.get();
    return 0;
}
