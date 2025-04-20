#pragma once
#include <memory>

#include "ivisual_obj.h"

class rect_obj : public ivisual_obj
{
public:
    rect_obj(SDL_Color color, const vector2& size, const vector2& start_pos);
    ~rect_obj() override = default;

    void resize(const vector2& new_size);
    void set_color(SDL_Color color);

    [[nodiscard]] vector2 size() const;
    [[nodiscard]] SDL_Color color() const;

    sdl_surface& get_surf() override;


private:
    std::shared_ptr<sdl_surface> m_rect;
    SDL_Color m_color;
};
