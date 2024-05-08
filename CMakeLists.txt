cmake_minimum_required(VERSION 3.18)
project(CityBuilder)


set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)
