#pragma once

#include <cstddef>
#include <cstdint>

namespace av {
using DataValue = std::uint32_t;
using Index = std::size_t;
using StepIndex = std::size_t;

constexpr Index kInvalidIndex = static_cast<Index>(-1);

enum class PlaybackState {
    Idle,
    Playing,
    Paused,
    Finished
};

enum class AlgorithmCategory {
    Sorting,
    Graph,
    Tree,
    Unknown
};

enum class AlgorithmType {
    BubbleSort,
    InsertionSort,
    SelectionSort,
    MergeSort,
    QuickSort,
    Unknown
};

enum class StepType {
    None,
    Compare,
    Swap,
    Write,
    MarkSorted,
    Done
};

enum class StatusCode {
    Ok,
    Warning,
    InvalidArgument,
    NotInitialized,
    InitializationFailed,
    OutOfRange,
    RuntimeError
};
} // namespace av
