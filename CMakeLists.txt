cmake_minimum_required(VERSION 3.25)
project(HelloSFML)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Ball.cpp Field.cpp Player.cpp CheckBoundaries.cpp GameObject.cpp GameObject.h Footballer.cpp Footballer.h Team.cpp Team.h)

add_executable(HelloSFML ${SOURCE_FILES} main.cpp Ball.cpp Field.cpp Player.cpp CheckBoundaries.cpp GameObject.cpp Footballer.cpp Team.cpp)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)