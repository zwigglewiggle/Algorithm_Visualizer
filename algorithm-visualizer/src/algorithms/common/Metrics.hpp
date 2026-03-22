#pragma once

#include <cstddef>

namespace av {
struct Metrics {
    std::size_t comparisons{0};
    std::size_t swaps{0};
    std::size_t writes{0};
    std::size_t sortedMarks{0};

    void reset() {
        comparisons = 0;
        swaps = 0;
        writes = 0;
        sortedMarks = 0;
    }
};
} // namespace av
