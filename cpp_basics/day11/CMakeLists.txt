cmake_minimum_required(VERSION 3.10)

project(day11)


find_package(PCL REQUIRED)


include_directories(
    ${PCL_INCLUDE_DIRS}
)


add_executable(main main.cpp)


add_executable(viewer_test viewer_test.cpp)


target_link_libraries(
    main
    ${PCL_LIBRARIES}
)


target_link_libraries(
    viewer_test
    ${PCL_LIBRARIES}
)

add_executable(viewer_point viewer_point.cpp)


target_link_libraries(
    viewer_point
    ${PCL_LIBRARIES}
)