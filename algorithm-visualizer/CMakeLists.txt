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
# 1. Find the SFML package and the required components
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

# ... (your add_executable line is probably here) ...

# 2. Link the SFML libraries to your executable
target_link_libraries(algorithm_visualizer PRIVATE sfml-graphics sfml-window sfml-system)