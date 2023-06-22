cmake_minimum_required(VERSION 3.25)
project(LevelCalculator)

set(CMAKE_CXX_STANDARD 17)
if (GNU EQUAL ${CMAKE_CXX_COMPILER_ID})
    message("HI")
else ()
    message("Compiler is not GNU, compiler is:")
    message(${CMAKE_CXX_COMPILER_ID})
endif ()


add_executable(LevelCalculator main.cpp)