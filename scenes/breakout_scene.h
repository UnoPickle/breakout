#pragma once
#include "iscene.h"
#include "../vo/image_obj.h"

class breakout_scene : public iscene {
public:
    breakout_scene();
    ~breakout_scene() override = default;


    void start() override;
    void update(double deltatime) override;
    void exit() override;

private:
    image_obj m_player;
};
