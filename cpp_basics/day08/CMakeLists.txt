cmake_minimum_required(VERSION 3.10)

project(PCLBasic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PCL REQUIRED COMPONENTS common io)

include_directories(${PCL_INCLUDE_DIRS})

add_executable(
    main
    main.cpp
)

target_link_libraries(
    main
    ${PCL_LIBRARIES}
)