#include <iostream>

#include "breakout.h"
#include "sdl.h"


int main(int argc, char* argv[])
{
    try
    {
        sdl sdl;
        breakout breakout;
        breakout.start();
    }catch (const std::exception& e)
    {
        std::cout << "Unhandled exception: " << e.what();
        system("pause");
    }

    return 0;
}
