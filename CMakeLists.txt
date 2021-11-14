cmake_minimum_required(VERSION 3.20)
project(shady)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(shady main.cpp Observer.cpp Observer.h Glasses.cpp Glasses.h Paint.cpp Paint.h Glasses.cpp Glasses.h Shades.cpp Shades.h Shape.cpp Shape.h File.cpp File.h)

include_directories(${OpenCV_INCLUDE_DIRS})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(shady ${OpenCV_LIBS})