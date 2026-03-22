#pragma once

#include "core/Result.hpp"
#include "core/Types.hpp"
#include "data/Presets.hpp"

#include <algorithm>
#include <utility>
#include <vector>

namespace av {
class DataSet {
public:
    using ValueType = DataValue;
    using ContainerType = std::vector<ValueType>;

    DataSet() = default;
    explicit DataSet(std::vector<DataValue> values) : m_values(std::move(values)), m_originalValues(m_values) {}
    DataSet(std::vector<DataValue> values, DataPresetType presetType)
        : m_values(std::move(values)), m_originalValues(m_values), m_presetType(presetType) {}

    std::size_t size() const { return m_values.size(); }
    bool empty() const { return m_values.empty(); }
    const ContainerType& values() const { return m_values; }
    const ContainerType& originalValues() const { return m_originalValues; }
    DataPresetType getPresetType() const { return m_presetType; }

    Result tryGet(Index index, DataValue& outValue) const {
        if (index >= m_values.size()) {
            return Result::failure(StatusCode::OutOfRange, "index out of range");
        }
        outValue = m_values[index];
        return Result::success();
    }

    Result set(Index index, DataValue value) {
        if (index >= m_values.size()) {
            return Result::failure(StatusCode::OutOfRange, "index out of range");
        }
        m_values[index] = value;
        return Result::success();
    }

    Result swap(Index left, Index right) {
        if (left >= m_values.size() || right >= m_values.size()) {
            return Result::failure(StatusCode::OutOfRange, "index out of range");
        }
        std::swap(m_values[left], m_values[right]);
        return Result::success();
    }

    Result resetToOriginal() {
        if (m_values.size() != m_originalValues.size()) {
            return Result::failure(StatusCode::RuntimeError, "reset failed");
        }
        m_values = m_originalValues;
        return Result::success();
    }

    void captureCurrentAsOriginal() { m_originalValues = m_values; }

    Result tryGetMaxValue(DataValue& outMax) const {
        if (m_values.empty()) {
            return Result::failure(StatusCode::InvalidArgument, "dataset is empty");
        }
        outMax = *std::max_element(m_values.begin(), m_values.end());
        return Result::success();
    }

    Result validate() const {
        if (m_values.empty() || m_originalValues.size() != m_values.size()) {
            return Result::failure(StatusCode::InvalidArgument, "invalid dataset");
        }
        return Result::success();
    }

private:
    ContainerType m_values{};
    ContainerType m_originalValues{};
    DataPresetType m_presetType{DataPresetType::Fixed};
};
} // namespace av
