#pragma once
#include "iscene.h"
#include "../vo/text_obj.h"

constexpr float SCORE_TEXT_SIZE = 80.0f;
constexpr SDL_Color SCORE_TEXT_COLOR = {0xff, 0xff, 0xff, 0};

constexpr float SCORE_TITLE_MARGIN = 10.0f;

constexpr float SCORE_NAV_MARGIN = 20.0f;

class game_over_scene : public iscene
{
public:
    game_over_scene(const uint64_t score);
    ~game_over_scene() override = default;

    void start() override;
    void update(double deltatime) override;
    void exit() override;

private:
    text_obj m_title;
    text_obj m_score;

    text_obj m_navigation_restart;
    text_obj m_navigation_menu;
};
