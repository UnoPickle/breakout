#include "game_over_scene.h"

#include "../breakout_defs.h"
#include "../resources/font_resource.h"
#include "../resources/resource_manager.h"

game_over_scene::game_over_scene(const uint64_t score) : m_title(
                                                             static_cast<font_resource*>(g_resource_manager.
                                                                 get_resource("assets/Jersey10-Regular.ttf"))->get_font(
                                                                 SCORE_TEXT_SIZE),
                                                             "Your score:", SCORE_TEXT_COLOR, {0, 0}),
                                                         m_score(
                                                             static_cast<font_resource*>(g_resource_manager.
                                                                 get_resource("assets/Jersey10-Regular.ttf"))->get_font(
                                                                 SCORE_TEXT_SIZE),
                                                             std::to_string(score), SCORE_TEXT_COLOR, {0, 0}),
                                                         m_navigation_restart(
                                                             static_cast<font_resource*>(g_resource_manager.
                                                                 get_resource("assets/Jersey10-Regular.ttf"))->get_font(
                                                                 SCORE_TEXT_SIZE),
                                                             "Press 'R' to restart", SCORE_TEXT_COLOR, {0, 0}),
                                                         m_navigation_menu(
                                                             static_cast<font_resource*>(g_resource_manager.
                                                                 get_resource("assets/Jersey10-Regular.ttf"))->get_font(
                                                                 SCORE_TEXT_SIZE),
                                                             "Press 'ESC' for menu", SCORE_TEXT_COLOR, {0, 0})

{
    m_score.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_score.get_surf().surface_object()->w / 2,
        static_cast<float>(breakout_defs::WINDOW_HEIGHT) / 2 - m_score.get_surf().surface_object()->h / 2
    });

    m_title.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_title.get_surf().surface_object()->w / 2,
        m_score.get_pos().y - m_title.get_surf().surface_object()->h / 2 - SCORE_TITLE_MARGIN
    });

    /*m_navigation_restart.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_navigation_restart.get_surf().surface_object()->w / 2,
        static_cast<float>(breakout_defs::WINDOW_HEIGHT) / 2 - m_score.get_surf().surface_object()->h / 2
    });*/

    add_object(m_title);
    add_object(m_score);
}

void game_over_scene::start()
{
}

void game_over_scene::update(double deltatime)
{
}

void game_over_scene::exit()
{
}
