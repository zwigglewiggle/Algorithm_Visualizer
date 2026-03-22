#include "data/Presets.hpp"

namespace av {
std::string toString(DataPresetType preset) {
    switch (preset) {
    case DataPresetType::Random:
        return "Random";
    case DataPresetType::Sorted:
        return "Sorted";
    case DataPresetType::Reversed:
        return "Reversed";
    case DataPresetType::NearlySorted:
        return "Nearly Sorted";
    case DataPresetType::Fixed:
        return "Fixed";
    }
    return "Unknown";
}

bool isRandomizedPreset(DataPresetType preset) {
    return preset == DataPresetType::Random;
}

std::vector<DataPresetType> allPresetTypes() {
    return {DataPresetType::Random, DataPresetType::Sorted, DataPresetType::Reversed, DataPresetType::NearlySorted, DataPresetType::Fixed};
}
} // namespace av
