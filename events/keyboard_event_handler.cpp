

#include "keyboard_event_handler.h"

#include "../input.h"

void keyboard_event_handler::handle_event(const SDL_KeyboardEvent& e)
{
    g_input.handle_input(e.scancode, e.down ? key_state::DOWN : key_state::UP);
}
