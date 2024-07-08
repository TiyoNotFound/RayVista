cmake_minimum_required(VERSION 3.10)
project(RaycastingSDK)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_library(Raycasting2D src/Raycasting2D.cpp)
add_library(Raycasting3D src/Raycasting3D.cpp)

add_executable(main2D main2D.cpp)
add_executable(main3D main3D.cpp)

target_link_libraries(main2D Raycasting2D)
target_link_libraries(main3D Raycasting3D)
