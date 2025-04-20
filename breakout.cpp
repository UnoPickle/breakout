#include "breakout.h"

#include <iostream>
#include <SDL3/SDL_timer.h>

#include "breakout_defs.h"
#include "state.h"
#include "resources/resource_manager.h"
#include "scenes/breakout_scene.h"
#include "scene_manager.hpp"
#include "resources/font_resource.h"

breakout::breakout() : _window("my game", breakout_defs::WINDOW_WIDTH, breakout_defs::WINDOW_HEIGHT, 0), _sdl_renderer(_window)
{
    load_resources();

    g_scene_manager.set_scene<breakout_scene>();
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
    g_scene_manager.active_scene()->update(deltatime);
}


void breakout::draw() const
{
    _sdl_renderer.clear();
    g_scene_manager.active_scene()->render(_sdl_renderer);
    _sdl_renderer.render();
}

void breakout::load_resources()
{
    g_resource_manager.load_surface("assets/snail.bmp");
    g_resource_manager.load_surface("assets/player.bmp");
    g_resource_manager.load_surface("assets/ball.bmp");
    g_resource_manager.load_font("assets/Jersey10-Regular.ttf");
}
