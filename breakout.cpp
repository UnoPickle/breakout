#include "breakout.h"

#include <iostream>
#include <ostream>
#include <SDL3/SDL_timer.h>

#include "state.h"
#include "scenes/test_scene.h"
#include "vo/image_obj.h"


breakout::breakout()
    : _current_scene(new test_scene()), _window("my game", 1920 / 2, 1080 / 2, 0), _sdl_renderer(_window)
{
    _current_scene->start();
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
        while (SDL_PollEvent(&sdl_event))
        {
            _event_man.handle_event(sdl_event);
        }

        const uint64_t cur_time = SDL_GetTicks();

        const uint64_t deltatime = cur_time - prev_time;
        std::cout << deltatime << std::endl;
        update(deltatime);
        draw();

        prev_time = cur_time;
    }
}

void breakout::update(uint64_t deltatime)
{
    _current_scene->update(deltatime);
}

void breakout::set_scene(iscene* new_scene)
{
    _current_scene->exit();

    _current_scene = new_scene;
    _current_scene->start();
}

void breakout::draw() const
{
    _sdl_renderer.clear();
    _current_scene->render(_sdl_renderer);
    _sdl_renderer.render();
}
