#pragma once
#include "iscene.h"
#include "../vo/rect_obj.h"
#include "../vo/text_obj.h"

constexpr float BOTTOM_MARGIN = 200.0f;

constexpr float TITLE_TEXT_SIZE = 120.0f;
constexpr SDL_Color TITLE_TEXT_COLOR = {0xff, 0xff, 0xff, 0};

constexpr float BUTTON_TEXT_SIZE = 80.0f;
const vector2 BUTTON_SIZE = {250, 100};

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
    text_obj m_title;

    rect_obj m_play_button_bg;
    text_obj m_play_button_text;
};
