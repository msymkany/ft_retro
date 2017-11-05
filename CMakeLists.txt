cmake_minimum_required(VERSION 3.8)
project(rush00)

set(CMAKE_CXX_STANDARD 98)
set (CMAKE_CXX_FLAGS   "-Wextra -Wall -Werror")

set(SOURCE_FILES
        main.cpp
        Field.cpp
        Field.hpp
        UserShip.cpp
        UserShip.hpp
        FlyingEssence.hpp
        FlyingEssence.cpp
        game.hpp
        Bullet.cpp
        Bullet.h EnemyShip.cpp EnemyShip.h)

add_executable(rush00 ${SOURCE_FILES})
add_library(ncurses)