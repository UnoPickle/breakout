#include "game_over_scene.h"

#include "breakout_scene.h"
#include "menu_scene.h"
#include "../breakout_defs.h"
#include "../input.h"
#include "../scene_manager.hpp"
#include "../resources/font_resource.h"
#include "../resources/resource_manager.h"

game_over_scene::game_over_scene::game_over_scene(const bool won, const uint64_t score) : m_win_title(
        static_cast<font_resource*>(g_resource_manager.
            get_resource("assets/Jersey10-Regular.ttf"))->get_font(
            TITLE_TEXT_SIZE),
        "You win!", SCENE_TEXT_COLOR, {0, 0}), m_title(
        static_cast<font_resource*>(g_resource_manager.
            get_resource("assets/Jersey10-Regular.ttf"))->get_font(
            TITLE_TEXT_SIZE),
        "Your score:", SCENE_TEXT_COLOR, {0, 0}),
    m_score(
        static_cast<font_resource*>(g_resource_manager.
            get_resource("assets/Jersey10-Regular.ttf"))->get_font(
            SCORE_TEXT_SIZE),
        std::to_string(score), SCENE_TEXT_COLOR, {0, 0}),
    m_navigation_restart(
        static_cast<font_resource*>(g_resource_manager.
            get_resource("assets/Jersey10-Regular.ttf"))->get_font(
            NAV_TEXT_SIZE),
        "Press '" + std::string(SDL_GetKeyName(SDL_GetKeyFromScancode(RESTART_SCANCODE, SDL_KMOD_NONE, false))) +
        "' to restart", SCENE_TEXT_COLOR, {0, 0}),
    m_navigation_menu(
        static_cast<font_resource*>(g_resource_manager.
            get_resource("assets/Jersey10-Regular.ttf"))->get_font(
            NAV_TEXT_SIZE),
        "Press '" + std::string(SDL_GetKeyName(SDL_GetKeyFromScancode(MENU_SCANCODE, SDL_KMOD_NONE, false))) +
        "' for menu", SCENE_TEXT_COLOR, {0, 0})

{
    m_score.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_score.get_surf().surface_object()->w / 2,
        static_cast<float>(breakout_defs::WINDOW_HEIGHT) / 2 - m_score.get_surf().surface_object()->h / 2 -
        BOTTOM_MARGIN
    });

    m_title.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_title.get_surf().surface_object()->w / 2,
        m_score.get_pos().y - m_score.get_surf().surface_object()->h / 2 - m_title.get_surf().surface_object()->h / 2 -
        SCORE_TITLE_MARGIN
    });

    m_win_title.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_win_title.get_surf().surface_object()->w / 2,
        m_title.get_pos().y - m_title.get_surf().surface_object()->h / 2 - m_win_title.get_surf().surface_object()->h / 2 -
        WIN_TITLE_MARGIN
    });

    m_navigation_restart.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_navigation_restart.get_surf().surface_object()->w / 2,
        m_score.get_pos().y + m_score.get_surf().surface_object()->h / 2 + m_navigation_restart.get_surf().
        surface_object()->h / 2 + SCORE_TITLE_MARGIN
    });

    m_navigation_menu.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_navigation_menu.get_surf().surface_object()->w / 2,
        m_navigation_restart.get_pos().y + m_navigation_menu.get_surf().surface_object()->h / 2 + RESTART_MENU_MARGIN
    });

    if (won)
    {
        add_object(m_win_title);
    }

    add_object(m_title);
    add_object(m_score);

    add_object(m_navigation_restart);
    add_object(m_navigation_menu);
}

void game_over_scene::game_over_scene::start()
{
}

void game_over_scene::game_over_scene::update(double deltatime)
{
    if (g_input.get_key(RESTART_SCANCODE) == key_state::DOWN)
    {
        g_scene_manager.set_scene<breakout_scene::breakout_scene>();
    }

    if (g_input.get_key(MENU_SCANCODE) == key_state::DOWN)
    {
        g_scene_manager.set_scene<menu_scene::menu_scene>();
    }
}

void game_over_scene::game_over_scene::exit()
{
}
