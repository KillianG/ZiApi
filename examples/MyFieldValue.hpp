//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include <string>
#include "FieldValue.hpp"

class MyValue : public ZiApi::FieldValue {
public:
    explicit MyValue(int value) { _value = value; };

    explicit MyValue(double value) { _value = value; };

    explicit MyValue(const std::string &value) { _value = value; }

    explicit MyValue(ValueList &&value) { _value = value; }

    const ValueVariant &getValue() const noexcept override { return _value; }

    FieldValue &operator=(const ValueVariant &valueVariant) override {
        _value = valueVariant;
        return *this;
    }
};