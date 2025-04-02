#ifndef BREAKOUT_H
#define BREAKOUT_H
#include "sdl/sdl_renderer.h"
#include "sdl/sdl_window.h"


class breakout
{
public:
    breakout();
    ~breakout();

    void start();

private:
    sdl_window _window;
    sdl_renderer _sdl_renderer;
};


#endif //BREAKOUT_H
