#include "breakout.h"

#include <iostream>
#include <SDL3/SDL_timer.h>

#include "state.h"
#include "resources/resource_manager.h"
#include "scenes/breakout_scene.h"


breakout::breakout() : _window("my game", 1920 / 2, 1080 / 2, 0), _sdl_renderer(_window)
{
    load_resources();

    _current_scene = new breakout_scene();
    _current_scene->start();
}

breakout::~breakout()
{
}

void breakout::start()
{
    uint64_t prev_time = SDL_GetTicksNS();

    while (state::running)
    {
        SDL_Event sdl_event;
        while (SDL_PollEvent(&sdl_event))
        {
            _event_man.handle_event(sdl_event);
        }

        const uint64_t cur_time = SDL_GetTicksNS();

        const double deltatime_ns = cur_time - prev_time;
        double deltatime_s = SDL_NS_TO_SECONDS(deltatime_ns);

        update(deltatime_s);
        draw();

        prev_time = cur_time;
    }
}

void breakout::update(double deltatime)
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

void breakout::load_resources()
{
    g_resource_manager.load_surface("assets/snail.bmp");
}
