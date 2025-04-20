#include "breakout_scene.h"

#include <iostream>
#include <random>

#include "game_over_scene.h"
#include "../breakout_defs.h"
#include "../input.h"
#include "../scene_manager.hpp"
#include "../resources/font_resource.h"
#include "../resources/image_resource.h"
#include "../resources/resource_manager.h"
#include "../sdl/sdl_font.h"
#include "../utils/collision_utils.h"

breakout_scene::breakout_scene::breakout_scene() : m_player(
                                       static_cast<image_resource*>(g_resource_manager.
                                           get_resource("assets/player.bmp"))->get_surface(),
                                       {
                                           0, 0
                                       }
                                   ), m_player_next_pos({0, 0}),
                                   m_player_dir(direction::LEFT), m_ball(
                                       static_cast<image_resource*>(g_resource_manager.
                                           get_resource("assets/ball.bmp"))->get_surface(),
                                       {
                                           0, 0
                                       }), m_ball_dir({
                                       static_cast<float>(direction::LEFT),
                                       static_cast<float>(direction::UP)
                                   }), m_ball_next_pos({0, 0})
{
    m_player_next_pos.y = static_cast<float>(breakout_defs::WINDOW_HEIGHT - PLAYER_BOTTOM_MARGIN - m_player.get_surf().
        surface_object()->
        h);
    m_player_next_pos.x = breakout_defs::WINDOW_WIDTH / 2 - m_player.get_surf().surface_object()->w / 2;

    m_player.set_pos(m_player_next_pos);

    m_ball_next_pos.x = m_player_next_pos.x + m_player.get_surf().surface_object()->w / 2;
    m_ball_next_pos.y = m_player_next_pos.y - m_player.get_surf().surface_object()->h - BALL_START_HEIGHT_FROM_PLAYER;


    add_object(m_ball);
    add_object(m_player);

}

void breakout_scene::breakout_scene::start()
{
    generate_tiles(LEVEL_AMOUNT);
}

void breakout_scene::breakout_scene::update(double deltatime)
{
    handle_input(deltatime);
    enforce_player_boundaries();
    move_player();

    handle_ball(deltatime);
    check_ball_boundaries();
    handle_ball_player_collision();
    handle_ball_tile_collision();
    move_ball();
}

void breakout_scene::breakout_scene::exit()
{
}

void breakout_scene::breakout_scene::generate_tiles(const uint32_t level_amount)
{
    for (uint32_t i = 0; i < level_amount; ++i)
    {
        generate_level({0, static_cast<float>((i + 1) * LEVEL_HEIGHT_MARGIN + i * TILE_HEIGHT)}, 10, TILE_HEIGHT,
                       { (uint8_t)rand(), (uint8_t)rand(), (uint8_t)rand(), 0});
    }
}

void breakout_scene::breakout_scene::generate_level(const vector2& start_location, const uint32_t tile_count,
                                    const uint32_t tile_height, const SDL_Color tile_color)
{
    const uint32_t tile_width = (breakout_defs::WINDOW_WIDTH - TILE_PADDING * (tile_count + 1)) / tile_count;
    const vector2 tile_size(tile_width, tile_height);

    for (uint32_t i = 0; i < tile_count; ++i)
    {
        vector2 tile_pos(start_location.x + TILE_PADDING * (i + 1) + tile_width * i, start_location.y);

        auto new_rect = std::make_shared<rect_obj>(tile_color, tile_size, tile_pos);
        scene_obj_id tile_id = add_object(*new_rect).id();

        m_tiles.emplace(tile_id, new_rect);
    }
}

void breakout_scene::breakout_scene::handle_input(double deltatime)
{
    if (g_input.get_key(SDL_SCANCODE_RIGHT) == key_state::DOWN || g_input.get_key(SDL_SCANCODE_LEFT) == key_state::DOWN)
    {
        m_player_velocity += deltatime * PLAYER_ACCELERATION;
        m_player_velocity = std::min(m_player_velocity, PLAYER_MAX_VELOCITY);

        if (g_input.get_key(SDL_SCANCODE_RIGHT) == key_state::DOWN)
        {
            m_player_dir = direction::RIGHT;
        }

        if (g_input.get_key(SDL_SCANCODE_LEFT) == key_state::DOWN)
        {
            m_player_dir = direction::LEFT;
        }
    }
    else
    {
        m_player_velocity -= deltatime * PLAYER_ACCELERATION;
        m_player_velocity = std::max(m_player_velocity, 0.0);
    }


    m_player_next_pos.x += deltatime * m_player_velocity * (m_player_dir == direction::RIGHT ? 1 : -1);
}

void breakout_scene::breakout_scene::move_ball()
{
    m_ball.set_pos(m_ball_next_pos);
}

void breakout_scene::breakout_scene::handle_ball(double deltatime)
{
    m_ball_next_pos.x += deltatime * m_ball_velocity * m_ball_dir.x;
    m_ball_next_pos.y += deltatime * m_ball_velocity * m_ball_dir.y;
}

void breakout_scene::breakout_scene::check_ball_boundaries()
{
    if (m_ball_next_pos.x < 0)
    {
        m_ball_next_pos.x = 0;
        m_ball_dir.x *= -1;
    }

    if (m_ball_next_pos.x > breakout_defs::WINDOW_WIDTH - m_ball.get_surf().surface_object()->w)
    {
        m_ball_next_pos.x = breakout_defs::WINDOW_WIDTH - m_ball.get_surf().surface_object()->w;
        m_ball_dir.x *= -1;
    }

    if (m_ball_next_pos.y < 0)
    {
        m_ball_next_pos.y = 0;
        m_ball_dir.y *= -1;
    }

    if (m_ball_next_pos.y > breakout_defs::WINDOW_HEIGHT - m_ball.get_surf().surface_object()->h)
    {
        end_game();
    }
}

void breakout_scene::breakout_scene::handle_ball_player_collision()
{
    SDL_FRect ball_rect = {
        m_ball_next_pos.x, m_ball_next_pos.y, static_cast<float>(m_ball.get_surf().surface_object()->w),
        static_cast<float>(m_ball.get_surf().surface_object()->h)
    };

    SDL_FRect player_rect = {
        m_player.get_pos().x, m_player.get_pos().y, static_cast<float>(m_player.get_surf().surface_object()->w),
        static_cast<float>(m_player.get_surf().surface_object()->h)
    };

    collision_utils::collision_dir_result player_cos_res = collision_utils::check_collision(ball_rect, player_rect);

    if (player_cos_res != 0)
    {
        if (m_ball.get_pos().y > player_rect.y + player_rect.h || m_ball.get_pos().y < player_rect.y
            || m_ball.get_pos().x > player_rect.x + player_rect.w || m_ball.get_pos().x < player_rect.x)
        {
            if (!m_ball_player_collision)
            {
                m_ball_dir.y *= -1;

                if ((m_ball.get_pos().x > player_rect.x + player_rect.w || m_ball.get_pos().x < player_rect.x) &&
                    m_ball_dir.x != static_cast<float>(m_player_dir))
                {
                    m_ball_dir.x *= -1;
                }
            }
        }
        m_ball_player_collision = true;

        inc_ball_velocity(m_player_velocity / 4);
    }else
    {
        m_ball_player_collision = false;
    }
}

void breakout_scene::breakout_scene::handle_ball_tile_collision()
{
    const SDL_FRect ball_rect = {
        m_ball_next_pos.x, m_ball_next_pos.y, static_cast<float>(m_ball.get_surf().surface_object()->w),
        static_cast<float>(m_ball.get_surf().surface_object()->h)
    };

    std::vector<scene_obj_id> to_remove;
    for (const auto& [id, tile_ptr] : m_tiles)
    {
        rect_obj* tile = tile_ptr.get();

        SDL_FRect tile_rect = {
            tile->get_pos().x,
            tile->get_pos().y,
            static_cast<float>(tile->get_surf().surface_object()->w),
            static_cast<float>(tile->get_surf().surface_object()->h)
        };

        if (const collision_utils::collision_dir_result res = collision_utils::check_collision(ball_rect, tile_rect);
            res !=
            0)
        {
            remove_object(id);
            to_remove.push_back(id);

            if (m_ball.get_pos().y > tile_rect.y + tile_rect.h || m_ball.get_pos().y < tile_rect.y)
            {
                m_ball_dir.y *= -1;
            }

            if (m_ball.get_pos().x > tile_rect.x + tile_rect.w || m_ball.get_pos().x < tile_rect.x)
            {
                m_ball_dir.x *= -1;
            }

            dec_ball_velocity(TILE_SLOWDOWN);

            m_score++;
        }
    }

    for (auto item : to_remove)
    {
        m_tiles.erase(item);
    }
}

void breakout_scene::breakout_scene::inc_ball_velocity(double velocity_to_inc)
{
    m_ball_velocity += velocity_to_inc;
    m_ball_velocity = std::min(m_ball_velocity, BALL_MAX_SPEED);
}

void breakout_scene::breakout_scene::dec_ball_velocity(double velocity_to_dec)
{
    m_ball_velocity -= velocity_to_dec;
    m_ball_velocity = std::max(m_ball_velocity, BALL_MIN_SPEED);
}

void breakout_scene::breakout_scene::move_player()
{
    m_player.set_pos(m_player_next_pos);
}

void breakout_scene::breakout_scene::enforce_player_boundaries()
{
    if (m_player_next_pos.x > breakout_defs::WINDOW_WIDTH - m_player.get_surf().surface_object()->w)
    {
        m_player_next_pos.x = breakout_defs::WINDOW_WIDTH - m_player.get_surf().surface_object()->w;
    }

    if (m_player_next_pos.x < 0)
    {
        m_player_next_pos.x = 0;
    }
}

void breakout_scene::breakout_scene::end_game()
{
    g_scene_manager.set_scene<game_over_scene::game_over_scene>(m_score);
}
