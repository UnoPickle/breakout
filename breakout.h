#ifndef BREAKOUT_H
#define BREAKOUT_H
#include "event_manager.h"
#include "sdl/sdl_renderer.h"
#include "sdl/sdl_window.h"


class breakout
{
public:
    breakout();
    ~breakout();

    void start();
    void update(uint64_t deltatime);


private:

    event_manager _event_man;

    sdl_window _window;
    sdl_renderer _sdl_renderer;
};


#endif //BREAKOUT_H
