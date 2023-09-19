cmake_minimum_required(VERSION 3.11)
project(lab2)
find_package(fmt)

set(SRCS
    src/main.cpp
    # src/refrigerated_trailer.cpp
    # src/trailer.cpp
    # src/truck.cpp
    # src/vehicle.cpp
)

add_executable(lab2 ${SRCS})
target_link_libraries(lab2 PUBLIC fmt::fmt)
