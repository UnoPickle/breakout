#pragma once
#include <cstdint>
#include <SDL3/SDL_rect.h>

namespace collision_utils
{
    using collision_dir_result = uint8_t;
    enum class collision_dir : uint8_t
    {
        UP_LEFT = 0b1,
        UP_RIGHT = 0b10,
        DOWN_LEFT = 0b100,
        DOWN_RIGHT = 0b1000
    };

    collision_dir_result check_collision(const SDL_FRect& collidee, const SDL_FRect& collider);

}
