cmake_minimum_required(VERSION 3.16)
project(Obsidian)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.28.5
)

FetchContent_MakeAvailable(SDL2)

FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.8.2
)

FetchContent_MakeAvailable(SDL2 SDL2_image)



add_library(ObsidianCore STATIC
    Obsidian/Core/Application.cpp
    Obsidian/Core/Window.cpp
    Obsidian/Maths/Vec2.cpp
    Obsidian/Renderer/Renderer.cpp
    Obsidian/Renderer/Camera.cpp
    Obsidian/Renderer/Texture.cpp
    Obsidian/Renderer/Renderer2D.cpp
    Obsidian/Assets/AssetManager.cpp
    Obsidian/Components/Sprite.cpp
    Obsidian/Events/Event.cpp
)

target_include_directories(ObsidianCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Obsidian)

target_include_directories(ObsidianCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ObsidianCore PUBLIC SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)

add_executable(Sandbox
    Sandbox/Sandbox.cpp
)

target_link_libraries(Sandbox PRIVATE ObsidianCore)