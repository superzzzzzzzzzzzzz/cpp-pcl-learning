cmake_minimum_required(VERSION 3.10)

project(EigenBasic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

add_executable(
    main
    main.cpp
)

target_link_libraries(
    main
    PRIVATE
    Eigen3::Eigen
)