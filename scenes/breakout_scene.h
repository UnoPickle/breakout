#pragma once
#include <unordered_map>

#include "iscene.h"
#include "../vo/image_obj.h"
#include "../vo/rect_obj.h"
#include "../vo/text_obj.h"

namespace breakout_scene
{
    constexpr uint32_t PLAYER_BOTTOM_MARGIN = 20;

    constexpr uint32_t LEVEL_AMOUNT = 1;
    constexpr uint32_t LEVEL_HEIGHT_MARGIN = 10;
    constexpr uint32_t TILE_PADDING = 10;

    constexpr uint32_t TILE_HEIGHT = 40;

    constexpr uint32_t BALL_START_HEIGHT_FROM_PLAYER = 10;

    constexpr double PLAYER_ACCELERATION = 3000;
    constexpr double PLAYER_DEACCELERATION = 3000;
    constexpr double PLAYER_MAX_VELOCITY = 1500;

    constexpr double BALL_MIN_SPEED = 300;
    constexpr double BALL_MAX_SPEED = 500;
    constexpr double TILE_SLOWDOWN = 25;

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
        void generate_level(const vector2& start_location, uint32_t tile_count, uint32_t tile_height,
                            SDL_Color tile_color);

        void handle_input(double deltatime);

        void move_ball();
        void handle_ball(double deltatime);
        void check_ball_boundaries();
        void handle_ball_player_collision();
        void handle_ball_tile_collision();

        void inc_ball_velocity(double velocity_to_inc);
        void dec_ball_velocity(double velocity_to_dec);

        void move_player();
        void enforce_player_boundaries();

        void check_win_condition();

        void end_game();

    private:
        std::unordered_map<scene_obj_id, std::shared_ptr<rect_obj>> m_tiles;

        image_obj m_player;
        vector2 m_player_next_pos;
        direction m_player_dir;
        double m_player_velocity = 0;

        image_obj m_ball;
        vector2 m_ball_dir;
        vector2 m_ball_next_pos;
        bool m_ball_player_collision = false;

        double m_ball_velocity = BALL_MIN_SPEED;

        uint64_t m_score = 0;
    };
}
