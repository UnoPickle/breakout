cmake_minimum_required(VERSION 3.28)
project(breakout)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/)

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
        vo/ivisual_obj.cpp
        vo/ivisual_obj.h
        vo/image_obj.cpp
        vo/image_obj.h
        vector2.cpp
        vector2.h
        event_manager.cpp
        event_manager.h
        input.cpp
        input.h
        state.cpp
        state.h
        events/keyboard_event_handler.cpp
        events/keyboard_event_handler.h
        main.cpp
        scenes/iscene.cpp
        scenes/iscene.h
        scenes/scene_obj.cpp
        scenes/scene_obj.h
        scenes/test_scene.cpp
        scenes/test_scene.h
        scenes/breakout_scene.cpp
        scenes/breakout_scene.h
        resources/resource_manager.cpp
        resources/resource_manager.h
        resources/iresource.cpp
        resources/iresource.h
        resources/image_resource.cpp
        resources/image_resource.h
        exceptions/resource_not_found_exception.cpp
        exceptions/resource_not_found_exception.h
        breakout_defs.h
        utils/collision_utils.cpp
        utils/collision_utils.h
        vo/rect_obj.cpp
        vo/rect_obj.h
        exceptions/sdl_surface_exception.cpp
        exceptions/sdl_surface_exception.h
        scene_manager.cpp
        scene_manager.hpp
        resources/font_resource.cpp
        resources/font_resource.h
        sdl/sdl_font.cpp
        sdl/sdl_font.h
        exceptions/sdl_font_init_exception.cpp
        exceptions/sdl_font_init_exception.h
        exceptions/sdl_font_exception.cpp
        exceptions/sdl_font_exception.h
)


find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_ttf CONFIG REQUIRED)
target_link_libraries(breakout PRIVATE SDL3_ttf::SDL3_ttf SDL3::SDL3)
target_compile_definitions(breakout PRIVATE SDL_MAIN_USE_CALLBACKS)
target_link_options(breakout PRIVATE -static)
