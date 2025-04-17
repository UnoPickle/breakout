#pragma once
#include <unordered_map>

#include "iscene.h"
#include "../vo/image_obj.h"
#include "../vo/rect_obj.h"

constexpr uint32_t PLAYER_BOTTOM_MARGIN = 20;
constexpr double PLAYER_SPEED = 600;

constexpr uint32_t LEVEL_AMOUNT = 5;
constexpr uint32_t LEVEL_HEIGHT_MARGIN = 10;
constexpr uint32_t TILE_PADDING = 10;

constexpr uint32_t TILE_HEIGHT = 40;

constexpr uint32_t BALL_START_HEIGHT_FROM_PLAYER = 10;

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

    void generate_tiles(uint32_t level_amount);
    void generate_level(const vector2& start_location, uint32_t tile_count, uint32_t tile_height, uint32_t tile_color);

    void handle_input(double deltatime);

    void move_ball();
    void handle_ball(double deltatime);
    void check_ball_boundaries();
    void handle_ball_player_collision();
    void handle_ball_tile_collision();

    void move_player();
    void enforce_player_boundaries();

private:
    std::unordered_map<scene_obj_id, std::shared_ptr<rect_obj>> m_tiles;

    image_obj m_player;
    vector2 m_player_next_pos;
    direction m_player_dir;

    image_obj m_ball;
    vector2 m_ball_dir;
    vector2 m_ball_next_pos;

    uint32_t m_ball_speed = 200;
};
