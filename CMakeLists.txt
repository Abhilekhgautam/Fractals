cmake_minimum_required(VERSION 3.25)
project(Fractals)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fractals main.cpp olcPixelGameEngine.h olcPixelGameEngine.h)

target_link_libraries(Fractals X11 GL pthread png  "stdc++fs")
