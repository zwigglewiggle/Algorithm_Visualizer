cmake_minimum_required(VERSION 3.20)
project(AlgorithmVisualizer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(av_core
    src/app/Application.cpp
    src/app/AppState.cpp
    src/algorithms/sorting/BubbleSort.cpp
    src/data/DataGenerator.cpp
    src/data/Presets.cpp
    src/playback/PlaybackController.cpp
    src/playback/Timeline.cpp
    src/rendering/Renderer.cpp
    src/rendering/views/ArrayView.cpp
    src/ui/UiManager.cpp
)

target_include_directories(av_core PUBLIC src)

add_executable(algorithm_visualizer src/main.cpp)
target_link_libraries(algorithm_visualizer PRIVATE av_core)

enable_testing()

function(add_av_test test_name source_file)
    add_executable(${test_name} ${source_file})
    target_link_libraries(${test_name} PRIVATE av_core)
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

add_av_test(av_data_tests src/tests/data_tests.cpp)
add_av_test(av_playback_tests src/tests/playback_tests.cpp)
add_av_test(av_sorting_tests src/tests/sorting_tests.cpp)
