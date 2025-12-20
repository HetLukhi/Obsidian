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
    Engine/src/Engine.cpp
)

target_include_directories(Engine
    PUBLIC Engine/include
)

add_executable(Sandbox
    sandbox/src/main.cpp
)

target_link_libraries(Sandbox
    PRIVATE Engine SDL2::SDL2 SDL2::SDL2main
)