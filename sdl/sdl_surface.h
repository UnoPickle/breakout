#ifndef SDL_SURFACE_H
#define SDL_SURFACE_H
#include <string>
#include <SDL3/SDL_surface.h>


class sdl_surface
{
public:
    explicit sdl_surface(SDL_Surface* surface);

    explicit sdl_surface(const std::string& filename);
    sdl_surface(const int width, const int height, const SDL_PixelFormat format);

    sdl_surface(const sdl_surface& other);
    ~sdl_surface();

    void fill_rect(const SDL_Rect* rect, uint32_t color) const;
    void blit_surface(const sdl_surface& src) const;
    void blit_surface(const sdl_surface& src, const SDL_Rect* src_rect, const SDL_Rect* dst_rect) const;

    [[nodiscard]] SDL_Surface* surface_object() const;
    sdl_surface& operator=(const sdl_surface& other);

private:
    SDL_Surface* m_surface;
};


#endif //SDL_SURFACE_H
