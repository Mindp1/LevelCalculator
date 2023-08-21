cmake_minimum_required(VERSION 3.25)
project(LevelCalculator)

set(CMAKE_CXX_STANDARD 17)
if ("GNU" STREQUAL ${CMAKE_CXX_COMPILER_ID})
    set(CMAKE_CXX_FLAGS "-static")
endif ()

add_executable(LevelCalculator Date.cpp Month.cpp Student.cpp main.cpp)