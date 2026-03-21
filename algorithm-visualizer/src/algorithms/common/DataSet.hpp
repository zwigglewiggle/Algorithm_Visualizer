#pragma once
#include "core/Types.hpp"
#include "core/Result.hpp"
#include "data/Presets.hpp"
#include <vector>;
namespace av{
    class DataSet{
        public:
            using ValueType = DataValue;
            using ContainerType = std::vector<ValueType>;

            DataSet(){
                m_values = std::vector<ValueType>();
                m_originalValues = std::vector<ValueType>();
                m_presetType = DataPresetType::Fixed;
            };
            explicit DataSet(std::vector<DataValue> values){
                m_values = values;
                m_originalValues = values;
                m_presetType = DataPresetType::Fixed;
            };
            DataSet(std::vector<DataValue> values, DataPresetType presetType){
                m_values = values;
                m_originalValues = values;
                m_presetType = presetType;
            };

            std::size_t size() const{
                return m_values.size();
            };
            bool empty() const{
                return m_values.empty();
            };
            const ContainerType& values() const{
                const ContainerType& res = m_values;
                return res;
            
            };
            const ContainerType& originalValues() const{
                const ContainerType& res = m_originalValues;
                return res;
            
            };
            DataPresetType getPresetType() const{
                return m_presetType;
            };

            Result tryGet(Index index, DataValue& outValue) const{
                if(index >= m_values.size()){
                   return Result::failure(StatusCode::OutOfRange, "index out of range");
                }
                outValue = m_values[index];
                return Result::success();
            };
            Result set(Index index, DataValue value){
                if(index >= m_values.size()){
                    return Result::failure(StatusCode::OutOfRange, "index out of range");
                }
                m_values[index] = value;
                return Result::success();

            };

            Result swap(Index left, Index right){
                if(left >= m_values.size() || right >= m_values.size()){
                    return Result::failure(StatusCode::OutOfRange, "index out of range");
                }
                std::swap(m_values[left], m_values[right]);
                return Result::success();
            };

            Result resetToOriginal(){
                if(m_values.size() != m_originalValues.size()){
                    return Result::failure(StatusCode::RuntimeError, "Runtime error reset to original");
                }
                m_values = m_originalValues;
                return Result::success();
            };

            void captureCurrentAsOriginal(){
                m_originalValues = m_values;
            };

            Result tryGetMaxValue(DataValue& outMax) const{
                if(m_values.empty()){
                    return Result::failure(StatusCode::InvalidArgument, "keine values bis jetzt");
                }
                outMax = m_values[0];
                for(const auto& value : m_values){
                    if(value > outMax){
                        outMax = value; 
                    }
                }
                return Result::success();

            };
            
            Result validate() const{
                if(m_values.empty() || m_originalValues.size() != m_values.size()){
                    return Result::failure(StatusCode::InvalidArgument, "invalid values");
                }
                return Result::success();

            };
            
        private:
            ContainerType m_values;
            ContainerType m_originalValues;
            DataPresetType m_presetType;


    };


}