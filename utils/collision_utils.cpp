#include "collision_utils.h"

collision_utils::collision_dir_result collision_utils::check_collision(const SDL_FRect& collidee,
                                                                       const SDL_FRect& collider)
{
    const SDL_FPoint up_left = {collidee.x, collidee.y};
    const SDL_FPoint up_right = {collidee.x + collidee.w, collidee.y};

    const SDL_FPoint down_left = {collidee.x, collidee.y + collidee.h};
    const SDL_FPoint down_right = {collidee.x + collidee.w, collidee.y + collidee.h};

    collision_dir_result res = 0;

    if (SDL_PointInRectFloat(&up_left, &collider))
    {
        res |= static_cast<collision_dir_result>(collision_dir::UP_LEFT);
    }

    if (SDL_PointInRectFloat(&up_right, &collider))
    {
        res |= static_cast<collision_dir_result>(collision_dir::UP_RIGHT);
    }

    if (SDL_PointInRectFloat(&down_left, &collider))
    {
        res |= static_cast<collision_dir_result>(collision_dir::DOWN_LEFT);
    }

    if (SDL_PointInRectFloat(&down_right, &collider))
    {
        res |= static_cast<collision_dir_result>(collision_dir::DOWN_RIGHT);
    }


    return res;
}
