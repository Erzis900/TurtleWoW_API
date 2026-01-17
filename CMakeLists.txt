cmake_minimum_required(VERSION 4.2.1)
project(TurtleWoW_API LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE
    src/Utils.cpp
    src/API/API.cpp
    src/API/Player.cpp
    src/API/Camera.cpp
    src/API/Unit.cpp
    src/API/GameObject.cpp
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        src
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/API.h)