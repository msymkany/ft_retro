cmake_minimum_required(VERSION 3.8)
project(rush00)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Field.cpp
        Field.hpp
        UserShip.cpp
        UserShip.hpp
        FlyingEssence.hpp
        FlyingEssence.cpp
        game.hpp)

add_executable(rush00 ${SOURCE_FILES})