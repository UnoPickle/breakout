#include "breakout.h"

#include <SDL3/SDL_timer.h>

#include "state.h"
#include "vo/image_obj.h"



breakout::breakout() : _window("my game", 1920 / 2, 1080 / 2, 0), _sdl_renderer(_window)
{
}

breakout::~breakout()
{
}

void breakout::start()
{
    uint64_t prev_time = SDL_GetTicks();

    while (state::running)
    {
        SDL_Event sdl_event;
        while(SDL_PollEvent(&sdl_event))
        {
            _event_man.handle_event(sdl_event);
        }

        uint64_t cur_time = SDL_GetTicks();

        const uint64_t deltatime = cur_time - prev_time;
        update(deltatime);

        prev_time = cur_time;
    }
}

void breakout::update(uint64_t deltatime)
{

}