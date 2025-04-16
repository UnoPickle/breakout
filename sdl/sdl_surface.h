#ifndef SDL_SURFACE_H
#define SDL_SURFACE_H
#include <string>
#include <SDL3/SDL_surface.h>


class sdl_surface
{
public:
    explicit sdl_surface(const std::string& filename);
    sdl_surface(const int width, const int height, const SDL_PixelFormat format);
    sdl_surface(const sdl_surface& other);
    ~sdl_surface();

    void fill_rect(const SDL_Rect* rect, uint32_t color) const;

    [[nodiscard]] SDL_Surface* surface_object() const;
    sdl_surface& operator=(const sdl_surface& other);

private:
    SDL_Surface* _surface;
};


#endif //SDL_SURFACE_H
