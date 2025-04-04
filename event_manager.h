#pragma once
#include <SDL3/SDL_events.h>


class event_manager
{
public:
    void handle_event(const SDL_Event& e);
};
