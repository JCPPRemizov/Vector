cmake_minimum_required(VERSION 3.26)
project(Allocator)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE ALLOCATOR_SOURCES src/*.cpp src/*.h)

add_executable(${PROJECT_NAME} ${ALLOCATOR_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src/Vector
        ${CMAKE_SOURCE_DIR}/src/Exception)
