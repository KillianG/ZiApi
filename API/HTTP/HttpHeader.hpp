//
// Created by nhyarlathotep on 24/01/19.
//

#pragma once

#include <map>
#include <memory>
#include "FieldValue.hpp"

namespace ZiApi {
    struct KeyCaseInsensitive : public std::binary_function<std::string, std::string, bool> {
        bool operator()(const std::string &s1, const std::string &s2) const {
            return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), [](char a, char b) { return std::tolower(a) < std::tolower(b); });
        }
    };

    /**
     * @brief Defines an Http header
     */
    using HttpHeader = std::map<std::string, std::unique_ptr<FieldValue>, KeyCaseInsensitive>;
}