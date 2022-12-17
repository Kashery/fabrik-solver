cmake_minimum_required(VERSION 3.18.4)

project(fabrik-solver C)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin )
add_subdirectory(src)
target_link_libraries(fabrik-solver PRIVATE m)


