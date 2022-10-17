cmake_minimum_required(VERSION 3.23)
project(RTGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(SFML-2.5.1/include)
add_subdirectory(SFML-2.5.1/)

add_executable(RTGame main.cpp)

target_link_libraries(RTGame sfml-graphics sfml-system sfml-window)


