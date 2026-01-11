cmake_minimum_required(VERSION 4.2.1)
project(TurtleWoW_API LANGUAGES CXX)


add_library(${PROJECT_NAME} SHARED 
    src/main.cpp
    src/Console.cpp
    src/Utils.cpp
    src/API/API.cpp
    src/API/Player.cpp
    src/API/Camera.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_options(${PROJECT_NAME} PRIVATE 
    -static
)
