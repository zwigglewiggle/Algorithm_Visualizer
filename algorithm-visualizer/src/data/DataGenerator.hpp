#pragma once

#include "algorithms/common/DataSet.hpp"

namespace av {
class DataGenerator {
public:
    static DataSet generate(std::size_t size, DataPresetType presetType);
};
} // namespace av
