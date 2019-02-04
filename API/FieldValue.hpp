//
// Created by nhyarlathotep on 28/01/19.
//

#pragma once

#include <vector>
#include <memory>
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
     * * `ValueMap`
     *
     * Usage example :
     * @include MyFieldValue.hpp
     * @sa https://en.cppreference.com/w/cpp/utility/variant
     */
    class FieldValue {
    public:
        virtual ~FieldValue() = default;

        /**
         * @brief Defines a list of FieldValues
         */
        using ValueList = std::vector<std::shared_ptr<FieldValue>>;

        /**
         * @brief Defines a map of FieldValues
         */
        using ValueMap = std::unordered_map<std::string, std::shared_ptr<FieldValue>>;

        /**
         * @brief Defines the possibles types of FieldValue
         */
        using ValueVariant = std::variant<int, bool, double, std::string, ValueList, ValueMap>;

        /**
         * @brief Gets the contained value
         */
        virtual const ValueVariant &getValue() const noexcept = 0;

        /**
         * @brief Set the contained value
         */
        virtual FieldValue &operator=(const ValueVariant &) = 0;

    protected:
        ValueVariant _value;        ///<The contained type
    };
}

/**
* @sa https://en.cppreference.com/w/cpp/utility/variant
*
* MyFieldValue.hpp : @include MyFieldValue.hpp
* Output : @include MyFieldValue.output
* MyFieldValue.cpp : @example MyFieldValue.cpp
*/