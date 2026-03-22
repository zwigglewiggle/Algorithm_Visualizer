#pragma once

#include "algorithms/common/Metrics.hpp"
#include "core/Types.hpp"

#include <array>
#include <vector>

namespace av {
struct AlgorithmStep {
    StepType type{StepType::None};
    std::array<Index, 2> indices{kInvalidIndex, kInvalidIndex};
    std::array<DataValue, 2> values{0, 0};
    std::vector<DataValue> snapshot{};
    std::vector<bool> sortedMask{};
    Metrics metrics{};
};
} // namespace av
