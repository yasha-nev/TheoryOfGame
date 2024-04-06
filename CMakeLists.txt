cmake_minimum_required(VERSION 3.13)

project(TheoryOfGame VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(
    include
    )

set(SRCS
    src/Criteria.cpp
    src/Matrix.cpp
    )

set(HEADERS
    include/Criteria.hpp
    include/Matrix.hpp
    )


add_compile_options(
    -Wall
    -Wextra
    )

add_executable(main main.cpp ${SRCS} ${HEADERS})
