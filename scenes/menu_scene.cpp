#include "menu_scene.h"

#include <iostream>

#include "breakout_scene.h"
#include "../breakout_defs.h"
#include "../input.h"
#include "../scene_manager.hpp"
#include "../state.h"
#include "../resources/font_resource.h"
#include "../resources/resource_manager.h"

menu_scene::menu_scene::menu_scene() : m_title(
                               static_cast<font_resource*>(g_resource_manager.get_resource(
                                   "assets/Jersey10-Regular.ttf"))->get_font(
                                   TITLE_TEXT_SIZE),
                               "BREAKOUT", TITLE_TEXT_COLOR, {0, 0}),
                           m_play_button(static_cast<font_resource*>(g_resource_manager.get_resource(
                                             "assets/Jersey10-Regular.ttf"))->get_font(
                                             BUTTON_TEXT_SIZE),
                                         "Play", TITLE_TEXT_COLOR, {0, 0}, BUTTON_PADDING, {0, 0}),
                           m_exit_button(static_cast<font_resource*>(g_resource_manager.get_resource(
                                             "assets/Jersey10-Regular.ttf"))->get_font(
                                             BUTTON_TEXT_SIZE),
                                         "Exit", TITLE_TEXT_COLOR, {0, 0}, BUTTON_PADDING, {0, 0})
{
    m_title.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_title.get_surf().surface_object()->w / 2,
        breakout_defs::WINDOW_HEIGHT / 2 - m_title.get_surf().surface_object()->h / 2 - BOTTOM_MARGIN
    });

    m_play_button.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_play_button.get_surf().surface_object()->w / 2,
        m_title.get_pos().y + m_title.get_surf().surface_object()->h / 2 + m_play_button.get_surf().surface_object()->h
        / 2 + PLAY_BUTTON_TITLE_MARGIN
    });

    m_exit_button.set_pos({
        static_cast<float>(breakout_defs::WINDOW_WIDTH) / 2 - m_exit_button.get_surf().surface_object()->w / 2,
        m_play_button.get_pos().y + m_play_button.get_surf().surface_object()->h + m_exit_button.get_surf().
        surface_object()->h
        / 2 + BUTTONS_MARGIN
    });

    select_button((uint64_t)menu_button_index::PLAY);

    add_object(m_title);
    add_object(m_play_button);
    add_object(m_exit_button);
}

void menu_scene::menu_scene::start()
{
}

void menu_scene::menu_scene::update(double deltatime)
{
    handle_button_press();
    handle_nav();
}

void menu_scene::menu_scene::exit()
{
}

void menu_scene::menu_scene::handle_nav()
{
    const uint64_t current_time = SDL_GetTicks();
    if (m_next_press_time > current_time)
    {
        return;
    }

    if (g_input.get_key(NAV_UP_SCANCODE) == key_state::DOWN)
    {
        if (m_cur_button_index == 0)
        {
            select_button(m_buttons.size() - 1);
        }
        else
        {
            select_button(m_cur_button_index - 1);
        }

        m_next_press_time = current_time + MILLISECONDS_PRESS_DELAY;
    }

    if (g_input.get_key(NAV_DOWN_SCANCODE) == key_state::DOWN)
    {
        if (m_cur_button_index >= m_buttons.size() - 1)
        {
            select_button(0);
        }
        else
        {
            select_button(m_cur_button_index + 1);
        }

        m_next_press_time = current_time + MILLISECONDS_PRESS_DELAY;
    }
}

void menu_scene::menu_scene::handle_button_press()
{
    if (g_input.get_key(PRESS_BUTTON_SCANCODE) == key_state::DOWN)
    {
        switch (static_cast<menu_button_index>(m_cur_button_index))
        {
        case menu_button_index::PLAY:
            {
                g_scene_manager.set_scene<breakout_scene::breakout_scene>();
            }
            break;
        case menu_button_index::EXIT:
            {
                state::running = false;
            }
            break;
        default: ;
        }
    }
}

void menu_scene::menu_scene::select_button(const uint64_t button_index)
{
    text_rect_obj* selected_button = m_buttons.at(m_cur_button_index);

    selected_button->set_bg_color(BUTTON_UNSELECTED_BG);
    selected_button->set_fg_color(BUTTON_UNSELECTED_FG);


    m_cur_button_index = button_index;
    selected_button = m_buttons.at(m_cur_button_index);
    selected_button->set_bg_color(BUTTON_SELECTED_BG);
    selected_button->set_fg_color(BUTTON_SELECTED_FG);
}
