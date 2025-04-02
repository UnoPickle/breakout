cmake_minimum_required(VERSION 3.28)
project(breakout)


add_executable(breakout
        sdl.cpp
        sdl.h
        sdl.h
        exceptions/breakout_exception.cpp
        exceptions/breakout_exception.h
        exceptions/sdl_startup_exception.cpp
        exceptions/sdl_startup_exception.h
        breakout.cpp
        breakout.h
        sdl/sdl_window.cpp
        sdl/sdl_window.h
        exceptions/sdl_window_init_exception.cpp
        exceptions/sdl_window_init_exception.h
        exceptions/sdl_exception.cpp
        exceptions/sdl_exception.h
        sdl/sdl_renderer.cpp
        sdl/sdl_renderer.h
        sdl/sdl_renderer.h
        exceptions/sdl_renderer_init_exception.cpp
        exceptions/sdl_renderer_init_exception.h
        sdl/sdl_texture.cpp
        sdl/sdl_texture.h
        sdl/sdl_surface.cpp
        sdl/sdl_surface.h
        exceptions/sdl_surface_init_exception.cpp
        exceptions/sdl_surface_init_exception.h
)

target_sources(
        breakout
        PRIVATE
        main.cpp
)


find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(breakout PRIVATE SDL3::SDL3)
target_compile_definitions(breakout PRIVATE SDL_MAIN_USE_CALLBACKS)
target_link_options(breakout PRIVATE -static)
