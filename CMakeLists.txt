cmake_minimum_required(VERSION 3.17)
project(my_game)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS window system graphics)

add_executable(my_game main.cpp Monster.cpp Monster.h Animation.cpp Animation.h Item.cpp Item.h Door.cpp Door.h Key.cpp Key.h Heart.cpp Heart.h BackGAnimation.cpp BackGAnimation.h)
target_link_libraries(my_game sfml-system sfml-window sfml-graphics sfml-audio)