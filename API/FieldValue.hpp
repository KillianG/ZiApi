//
// Created by nhyarlathotep on 28/01/19.
//

#pragma once

#include <vector>
#include <variant>
#include <unordered_map>

namespace ZiApi {
    /**
     * @brief Contains a generic type
     *
     * @details The contained type can be :
     * * `int`
     * * `bool`
     * * `double`
     * * `std::string`
     * * `ValueList`
     *
     * @warning `ZiApi::FieldValue value = "Hello";` create the object with a `bool` instead of a `std::string`
     * @warning `ZiApi::FieldValue value = std::string("Hello");` works
     *
     * Usage example :
     * @include MyFieldValue.cpp
     * Output : @include MyFieldValue.output
     * @sa https://en.cppreference.com/w/cpp/utility/variant
     */
    class FieldValue {
    public:
        /**
         * @brief Defines a list of FieldValues
         */
        using ValueList = std::vector<FieldValue>;

        /**
         * @brief Defines the possibles types of FieldValue
         */
        using ValueVariant = std::variant<int, bool, double, std::string, ValueList>;

    public:
        FieldValue() = default;
        FieldValue(ValueVariant value) : _value(std::move(value)) {}

        /**
         * @brief Gets the contained value
         */
        const ValueVariant &getValue() const noexcept { return _value; }

        /**
         * @brief Set the contained value
         */
        FieldValue &operator=(const ValueVariant &other) {
            _value = other;
            return *this;
        };

    private:
        ValueVariant _value;        ///<The contained type
    };
}

/**
* @sa https://en.cppreference.com/w/cpp/utility/variant
*
* Output : @include MyFieldValue.output
* MyFieldValue.cpp : @example MyFieldValue.cpp
*/