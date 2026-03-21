#include "Presets.hpp"

std::string av::toString(DataPresetType preset){
    switch(preset){
        case DataPresetType::Random: return "Random";
        case DataPresetType::Sorted: return "Sorted";
        case DataPresetType::Reversed: return "Reversed";
        case DataPresetType::NearlySorted: return "Nearly Sorted";
        case DataPresetType::Fixed: return "Fixed";
        default: return "Unknown";
    }
}
bool av::isRandomizedPreset(DataPresetType preset){
    switch(preset){
        case DataPresetType::Random: return true;
        case DataPresetType::Sorted: return false;
        case DataPresetType::Reversed: return false;
        case DataPresetType::NearlySorted: return false;
        case DataPresetType::Fixed: return false;   

    }
}
std::vector<av::DataPresetType> av::allPresetTypes(){
    return {
        DataPresetType::Random, DataPresetType::Sorted, DataPresetType::Reversed, DataPresetType::NearlySorted, DataPresetType::Fixed
    };


}