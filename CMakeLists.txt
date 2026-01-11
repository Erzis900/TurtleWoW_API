cmake_minimum_required(VERSION 4.2.1)
project(TurtleWoW_API LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED 
    src/main.cpp
    src/Console.cpp
    src/API.cpp
    src/Functions.cpp
    src/Utils.cpp
)

target_link_options(${PROJECT_NAME} PRIVATE 
    -static
)
