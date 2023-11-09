cmake_minimum_required(VERSION 3.11)
project(lab4)
find_package(fmt)

set(SRCS
    src/main.cpp
)
add_compile_options(-Wall -Wextra -Wpedantic)
add_executable(lab4 ${SRCS})
target_link_libraries(lab4 PUBLIC fmt::fmt)
