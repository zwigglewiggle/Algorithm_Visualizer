#include "data/DataGenerator.hpp"

#include <algorithm>
#include <numeric>
#include <random>

namespace {
std::mt19937& rng() {
    static std::mt19937 engine{std::random_device{}()};
    return engine;
}
}

namespace av {
DataSet DataGenerator::generate(std::size_t size, DataPresetType presetType) {
    std::vector<DataValue> values(size);
    std::iota(values.begin(), values.end(), 1U);

    switch (presetType) {
    case DataPresetType::Random:
        std::shuffle(values.begin(), values.end(), rng());
        break;
    case DataPresetType::Sorted:
        break;
    case DataPresetType::Reversed:
        std::reverse(values.begin(), values.end());
        break;
    case DataPresetType::NearlySorted:
        if (size > 3) {
            auto swapCount = std::max<std::size_t>(1, size / 10);
            for (std::size_t i = 0; i < swapCount; ++i) {
                auto left = static_cast<Index>(rng()() % size);
                auto right = static_cast<Index>(rng()() % size);
                std::swap(values[left], values[right]);
            }
        }
        break;
    case DataPresetType::Fixed:
        values = {8, 3, 5, 1, 9, 2, 7, 4, 6};
        break;
    }

    return DataSet(values, presetType);
}
} // namespace av
