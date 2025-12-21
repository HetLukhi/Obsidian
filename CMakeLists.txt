cmake_minimum_required(VERSION 3.16)
project(Obsidian LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.0
)

FetchContent_MakeAvailable(SDL2)

add_library(Engine
    Engine/src/Graphics/graphics.cpp
    Engine/src/Core/engine.cpp
    Engine/src/Input/input.cpp
)

target_include_directories(Engine
    PUBLIC Engine/include
)

target_link_libraries(Engine
    PUBLIC SDL2::SDL2 SDL2::SDL2main
)

add_executable(Sandbox
    Sandbox/src/main.cpp
)

target_link_libraries(Sandbox
    PRIVATE Engine SDL2::SDL2 SDL2::SDL2main
)

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:Sandbox>
)