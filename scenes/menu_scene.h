#pragma once
#include "iscene.h"
#include "../vo/rect_obj.h"
#include "../vo/text_obj.h"
#include "../vo/text_rect_obj.h"

namespace menu_scene
{
    constexpr float BOTTOM_MARGIN = 200.0f;

    constexpr float TITLE_TEXT_SIZE = 120.0f;
    constexpr SDL_Color TITLE_TEXT_COLOR = {0xff, 0xff, 0xff, 0};

    constexpr float BUTTON_TEXT_SIZE = 80.0f;
    constexpr float BUTTON_PADDING = 2.0f;

    constexpr SDL_Color BUTTON_UNSELECTED_BG = {0, 0, 0, 0};
    constexpr SDL_Color BUTTON_SELECTED_BG = {0xff, 0xff, 0xff, 0};

    constexpr SDL_Color BUTTON_UNSELECTED_FG = {0xff, 0xff, 0xff, 0};
    constexpr SDL_Color BUTTON_SELECTED_FG = {0, 0, 0, 0};

    constexpr SDL_Color PLAY_BUTTON_TEXT_COLOR = {0xff, 0xff, 0xff, 0};
    constexpr float PLAY_BUTTON_TITLE_MARGIN = 90.0f;

    constexpr float BUTTONS_MARGIN = 10.0f;

    constexpr uint64_t MILLISECONDS_PRESS_DELAY = 200;

    constexpr SDL_Scancode PRESS_BUTTON_SCANCODE = SDL_SCANCODE_RETURN;
    constexpr SDL_Scancode NAV_UP_SCANCODE = SDL_SCANCODE_UP;
    constexpr SDL_Scancode NAV_DOWN_SCANCODE = SDL_SCANCODE_DOWN;

    enum class menu_button_index : uint64_t
    {
        PLAY = 0,
        EXIT = 1,
    };

    class menu_scene : public iscene
    {
    public:
        menu_scene();
        ~menu_scene() override = default;

        void start() override;
        void update(double deltatime) override;
        void exit() override;

    private:
        void handle_nav();
        void handle_button_press();
        void select_button(uint64_t button_index);


        text_obj m_title;

        text_rect_obj m_play_button;
        text_rect_obj m_exit_button;

        std::vector<text_rect_obj*> m_buttons = {&m_play_button, &m_exit_button};
        uint64_t m_cur_button_index = 0;

        uint64_t m_next_press_time = 0;
    };
}
