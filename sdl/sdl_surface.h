#ifndef SDL_SURFACE_H
#define SDL_SURFACE_H
#include <string>
#include <SDL3/SDL_surface.h>


class sdl_surface
{
public:
    explicit sdl_surface(const std::string& filename);
    sdl_surface(const sdl_surface& other);
    ~sdl_surface();

    [[nodiscard]] SDL_Surface* surface_object() const;
    sdl_surface& operator=(const sdl_surface& other);

private:
    SDL_Surface* _surface;
};


#endif //SDL_SURFACE_H
