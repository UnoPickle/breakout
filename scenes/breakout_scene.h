#pragma once
#include "iscene.h"
#include "../vo/image_obj.h"
#include "../vo/rect_obj.h"

constexpr uint32_t PLAYER_BOTTOM_MARGIN = 20;
constexpr double PLAYER_SPEED = 600;
constexpr double BALL_SPEED = 200;

enum class direction
{
    LEFT = -1,
    RIGHT = 1,
    UP = -1,
    DOWN = 1,
};

class breakout_scene : public iscene
{
public:
    breakout_scene();
    ~breakout_scene() override = default;


    void start() override;
    void update(double deltatime) override;
    void exit() override;

    void handle_input(double deltatime);

    void move_ball();
    void handle_ball(double deltatime);
    void enforce_ball_boundaries();
    void handle_ball_collisions();

    void move_player();
    void enforce_player_boundaries();

private:
    rect_obj rect;

    image_obj m_ball;
    vector2 m_ball_dir;
    vector2 m_ball_next_pos;

    image_obj m_player;
    vector2 m_player_next_pos;
    direction m_player_dir;
};
