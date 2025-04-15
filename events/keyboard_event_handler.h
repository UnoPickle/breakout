#pragma once
#include <SDL3/SDL_events.h>


class keyboard_event_handler
{
public:
    static void handle_event(const SDL_KeyboardEvent& e);
};
