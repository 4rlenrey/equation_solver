cmake_minimum_required(VERSION 3.10)
project(Equalizatinator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/code/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/code/Core/include/
    )
    
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/code/src/ Engine_Sources)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/code/Core/src/ Core_Sources)

set(
    SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/code/main.cpp
    ${Engine_Sources}
    ${Core_Sources}
)

add_executable(a ${SRC})