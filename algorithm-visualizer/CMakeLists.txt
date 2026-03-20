cmake_minimum_required(VERSION 3.20)
project(AlgorithmVisualizer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(algorithm_visualizer
    src/main.cpp
    src/app/Application.cpp
    src/app/AppState.cpp
)

target_include_directories(algorithm_visualizer PRIVATE src)
