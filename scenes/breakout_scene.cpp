#include "breakout_scene.h"

#include <iostream>
#include <ostream>

#include "../breakout_defs.h"
#include "../input.h"
#include "../resources/image_resource.h"
#include "../resources/resource_manager.h"
#include "../utils/collision_utils.h"

breakout_scene::breakout_scene() : m_ball(
                                       static_cast<image_resource*>(g_resource_manager.
                                           get_resource("assets/ball.bmp"))->get_surface(),
                                       {
                                           0, 0
                                       }), m_ball_next_pos({0, 0}),
                                   m_ball_dir({
                                       static_cast<float>(direction::RIGHT),
                                       static_cast<float>(direction::DOWN)
                                   }), m_player(
                                       static_cast<image_resource*>(g_resource_manager.
                                           get_resource("assets/player.bmp"))->get_surface(),
                                       {
                                           0, 0
                                       }
                                   ), m_player_next_pos({0, 0}),
                                   rect(0xff0000, {20, 100}, {0, 0})
{
    m_player_next_pos.y = static_cast<float>(breakout_defs::WINDOW_HEIGHT - PLAYER_BOTTOM_MARGIN - m_player.get_surf().
        surface_object()->
        h);
    m_player_next_pos.x = breakout_defs::WINDOW_WIDTH / 2 - m_player.get_surf().surface_object()->w / 2;

    m_player.set_pos(m_player_next_pos);


    add_object(m_ball);
    add_object(m_player);
    add_object(rect);
}

void breakout_scene::start()
{
}

void breakout_scene::update(double deltatime)
{
    handle_input(deltatime);
    enforce_player_boundaries();
    move_player();

    handle_ball(deltatime);
    enforce_ball_boundaries();
    handle_ball_collisions();
    move_ball();
}

void breakout_scene::exit()
{
}

void breakout_scene::handle_input(double deltatime)
{
    if (g_input.get_key(SDL_SCANCODE_RIGHT) == key_state::DOWN)
    {
        m_player_next_pos.x += deltatime * PLAYER_SPEED;
        m_player_dir = direction::RIGHT;
    }

    if (g_input.get_key(SDL_SCANCODE_LEFT) == key_state::DOWN)
    {
        m_player_next_pos.x -= deltatime * PLAYER_SPEED;
        m_player_dir = direction::LEFT;
    }
}

void breakout_scene::move_ball()
{
    m_ball.set_pos(m_ball_next_pos);
}

void breakout_scene::handle_ball(double deltatime)
{
    m_ball_next_pos.x += deltatime * BALL_SPEED * m_ball_dir.x;
    m_ball_next_pos.y += deltatime * BALL_SPEED * m_ball_dir.y;
}

void breakout_scene::enforce_ball_boundaries()
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
        m_ball_next_pos.y = breakout_defs::WINDOW_HEIGHT - m_ball.get_surf().surface_object()->h;
        m_ball_dir.y *= -1;
    }
}

void breakout_scene::handle_ball_collisions()
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
        if (ball_rect.y > player_rect.y + player_rect.h || ball_rect.y < player_rect.y)
        {
            m_ball_dir.y *= -1;
        }

        if (ball_rect.x > player_rect.x + player_rect.w || ball_rect.x < player_rect.x)
        {
            if (m_ball_dir.x != static_cast<float>(m_player_dir))
            {
                m_ball_dir.x *= -1;
            }
        }
    }
}

void breakout_scene::move_player()
{
    m_player.set_pos(m_player_next_pos);
}

void breakout_scene::enforce_player_boundaries()
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
