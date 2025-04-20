#include "menu_scene.h"

#include "../breakout_defs.h"
#include "../resources/font_resource.h"
#include "../resources/resource_manager.h"

menu_scene::menu_scene() : m_title(
                               static_cast<font_resource*>(g_resource_manager.get_resource(
                                   "assets/Jersey10-Regular.ttf"))->get_font(
                                   TITLE_TEXT_SIZE),
                               "BREAKOUT", TITLE_TEXT_COLOR, {0, 0}),
                           m_play_button_bg(0xff, BUTTON_SIZE, {0, 0}),
                           m_play_button_text(
                               static_cast<font_resource*>(g_resource_manager.get_resource(
                                   "assets/Jersey10-Regular.ttf"))->get_font(
                                   BUTTON_TEXT_SIZE),
                               "Play", PLAY_BUTTON_TEXT_COLOR, {0, 0})
{
    m_title.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_title.get_surf().surface_object()->w / 2,
        breakout_defs::WINDOW_HEIGHT / 2 - m_title.get_surf().surface_object()->h / 2 - BOTTOM_MARGIN
    });

    m_play_button_text.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_play_button_text.get_surf().surface_object()->w / 2,
        m_title.get_pos().y + m_title.get_surf().surface_object()->h / 2 + m_play_button_text.get_surf().surface_object()->h / 2 + PLAY_BUTTON_TITLE_MARGIN
    });


    add_object(m_title);
    add_object(m_play_button_text);
}

void menu_scene::start()
{
}

void menu_scene::update(double deltatime)
{
}

void menu_scene::exit()
{
}
