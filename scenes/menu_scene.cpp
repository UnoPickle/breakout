#include "menu_scene.h"

#include "../breakout_defs.h"
#include "../resources/font_resource.h"
#include "../resources/resource_manager.h"

menu_scene::menu_scene() : m_title(
                               static_cast<font_resource*>(g_resource_manager.get_resource(
                                   "assets/Jersey10-Regular.ttf"))->get_font(
                                   TITLE_TEXT_SIZE),
                               "BREAKOUT", TITLE_TEXT_COLOR, {0, 0}),
                           m_play_button(static_cast<font_resource*>(g_resource_manager.get_resource(
                                             "assets/Jersey10-Regular.ttf"))->get_font(
                                             BUTTON_TEXT_SIZE),
                                         "BREAKOUT", TITLE_TEXT_COLOR, {0, 0}, BUTTON_PADDING, {0, 0})
{
    select_button(&m_play_button);

    m_title.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_title.get_surf().surface_object()->w / 2,
        breakout_defs::WINDOW_HEIGHT / 2 - m_title.get_surf().surface_object()->h / 2 - BOTTOM_MARGIN
    });

    m_play_button.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_play_button.get_surf().surface_object()->w / 2,
        m_title.get_pos().y + m_title.get_surf().surface_object()->h / 2 + m_play_button.get_surf().surface_object()->h
        / 2 + PLAY_BUTTON_TITLE_MARGIN
    });


    add_object(m_title);
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

void menu_scene::select_button(text_rect_obj* button)
{
    if (m_selected_button != nullptr)
    {
        m_selected_button->set_bg_color(BUTTON_UNSELECTED_BG);
        m_selected_button->set_fg_color(BUTTON_UNSELECTED_FG);
    }

    m_selected_button = button;
    m_selected_button->set_bg_color(BUTTON_SELECTED_BG);
    m_selected_button->set_fg_color(BUTTON_SELECTED_FG);
}
