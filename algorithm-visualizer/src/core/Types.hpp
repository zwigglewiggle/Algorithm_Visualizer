#pragma once
#include <cstddef>
namespace av{
    using DataValue = std::size_t;
    using Index = std::size_t;
    using StepIndex = std::size_t;

    enum class PlaybackState{
        Idle, Playing, Paused, Finished
    };
    enum class AlgorithmCategory{
        Sorting, Graph, Tree, Unknown
    };
    enum class AlgorithmType{
        BubbleSort, InsertionSort, SelectionSort, MergeSort, QuickSort, Unknown

    };
    enum class StepType{
        None, Compare, Swap, Write, MarkSorted, Done
    };
    enum class StatusCode{
        Ok, Warning, InvalidArgument, NotInitialized, InitializationFailed, OutOfRange
        , RuntimeError
    };
}