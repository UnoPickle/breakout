#include "event_manager.h"

#include "state.h"
#include "events/keyboard_event_handler.h"

void event_manager::handle_event(const SDL_Event& e)
{
    switch (e.type)
    {
    case SDL_EVENT_QUIT:
        state::running = false;
        break;

    case SDL_EVENT_KEY_UP:
    case SDL_EVENT_KEY_DOWN:
        keyboard_event_handler::handle_event((const SDL_KeyboardEvent&)e);
        break;


    default: ;
    }
n}
