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


add_library(ObsidianCore
    Obsidian/Core/Application.cpp
    Obsidian/Core/Window.cpp
    Obsidian/Renderer/Renderer.cpp
    Obsidian/Events/Event.cpp
)

target_include_directories(ObsidianCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Obsidian)

target_include_directories(ObsidianCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ObsidianCore PUBLIC SDL2::SDL2 SDL2::SDL2main)

add_executable(Sandbox
    Sandbox/Sandbox.cpp
)

target_link_libraries(Sandbox PRIVATE ObsidianCore)