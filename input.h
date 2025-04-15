#pragma once
#include <cstdint>
#include <SDL3/SDL_keycode.h>

enum class key_state : uint8_t
{
    UP = 0,
    DOWN = 1
};

class input
{
public:
    void handle_input(SDL_Scancode code, key_state state);
    key_state get_key(SDL_Scancode code) const;

private:
    key_state _keys[SDL_SCANCODE_COUNT] = {key_state::UP};
};

extern input g_input;
