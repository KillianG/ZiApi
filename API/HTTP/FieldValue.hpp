//
// Created by nhyarlathotep on 28/01/19.
//

#pragma once

#include <vector>
#include <variant>
#include <functional>
#include <unordered_map>

namespace ZiApi {
    /**
     * @brief Contains a generic type
     */
    class FieldValue {
    public:
        /**
         * @brief Defines a list of FieldValues
         */
        using ValueList = std::vector<std::reference_wrapper<FieldValue>>;

        /**
         * @brief Defines a map of FieldValues
         */
        using ValueMap = std::unordered_map<std::string, std::reference_wrapper<FieldValue>>;

        /**
         * @brief Defines the possibles types of FieldValue
         */
        using ValueVarient = std::variant<int, bool, double, std::string, ValueList, ValueMap>;

        /**
         * @brief Gets  the contained value
         */
        virtual const ValueVarient &getValue() const noexcept = 0;

        virtual FieldValue &operator=(const ValueVarient &) noexcept = 0;

    protected:
        ValueVarient _value;
    };
}