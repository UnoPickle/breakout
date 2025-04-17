#pragma once
#include <memory>

#include "ivisual_obj.h"

class rect_obj : public ivisual_obj
{
public:
    rect_obj(uint32_t color, const vector2& size, const vector2& start_pos);

    void resize(const vector2& new_size);
    void set_color(uint32_t color);

    sdl_surface& get_surf() override;

    ~rect_obj() override = default;

private:
    std::shared_ptr<sdl_surface> m_rect;
    uint32_t m_color;
};
