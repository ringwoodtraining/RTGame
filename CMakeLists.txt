cmake_minimum_required(VERSION 3.23)
project(RTGame)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(SFML-2.5.1/)
add_subdirectory(box2d-2.4.1)

include_directories(SFML-2.5.1/include)
include_directories(box2d-2.4.1/include)

add_executable(RTGame main.cpp)

target_link_libraries(RTGame box2d sfml-graphics sfml-system sfml-window)


