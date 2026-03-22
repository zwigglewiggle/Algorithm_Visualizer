#pragma once

#include "algorithms/common/AlgorithmStep.hpp"

#include <string>

namespace av {
class ArrayView {
public:
    std::string buildFrame(const AlgorithmStep* step, std::size_t maxBars = 32) const;
};
} // namespace av
