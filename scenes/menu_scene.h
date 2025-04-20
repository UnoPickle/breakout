#pragma once
#include "iscene.h"
#include "../vo/rect_obj.h"
#include "../vo/text_obj.h"
#include "../vo/text_rect_obj.h"

constexpr float BOTTOM_MARGIN = 200.0f;

constexpr float TITLE_TEXT_SIZE = 120.0f;
constexpr SDL_Color TITLE_TEXT_COLOR = {0xff, 0xff, 0xff, 0};

constexpr float BUTTON_TEXT_SIZE = 80.0f;
constexpr float BUTTON_PADDING = 2.0f;

constexpr SDL_Color BUTTON_UNSELECTED_BG = { 0, 0, 0, 0};
constexpr SDL_Color BUTTON_SELECTED_BG = { 0xff, 0xff, 0xff, 0};

constexpr SDL_Color BUTTON_UNSELECTED_FG = { 0xff, 0xff, 0xff, 0};
constexpr SDL_Color BUTTON_SELECTED_FG = { 0, 0, 0, 0};

constexpr SDL_Color PLAY_BUTTON_TEXT_COLOR = {0xff, 0xff, 0xff, 0};
constexpr float PLAY_BUTTON_TITLE_MARGIN = 90.0f;

class menu_scene : public iscene
{
public:
    menu_scene();
    ~menu_scene() override = default;

    void start() override;
    void update(double deltatime) override;
    void exit() override;

private:
    void select_button(text_rect_obj* button);
    text_rect_obj* m_selected_button = nullptr;


    text_obj m_title;

    text_rect_obj m_play_button;
};
