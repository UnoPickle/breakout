#include "input.h"

input g_input;

void input::handle_input(const SDL_Scancode code, const key_state state)
{
    _keys[code] = state;
}

key_state input::get_key(const SDL_Scancode code) const
{
    return _keys[code];
}
