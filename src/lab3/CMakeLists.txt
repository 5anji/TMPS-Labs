cmake_minimum_required(VERSION 3.11)
project(lab3)
find_package(fmt)

set(SRCS
    src/main.cpp
)

add_executable(lab3 ${SRCS})
target_link_libraries(lab3 PUBLIC fmt::fmt)
