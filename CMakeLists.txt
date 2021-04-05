cmake_minimum_required(VERSION 3.10)
project(Equalizatinator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread")
find_package (Threads)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/code/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/code/Core/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/code/gui/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/code/gui/components/include/
    )
    
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/code/src/ Engine_Sources)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/code/Core/src/ Core_Sources)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/code/gui/src/ gui_Sources)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/code/gui/src/components/ gui_components_Sources)

set(
    SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/code/main.cpp
    ${Engine_Sources}
    ${Core_Sources}
    ${gui_Sources}
    ${gui_components_Sources}
)

link_libraries(
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

add_executable(a ${SRC})
