#pragma once
#include<string>
#include<vector>

namespace av{
    enum class DataPresetType{
        Random, Sorted, Reversed, NearlySorted, Fixed
    };
    std::string toString(DataPresetType preset);
    bool isRandomizedPreset(DataPresetType preset);
    std::vector<DataPresetType> allPresetTypes();
}