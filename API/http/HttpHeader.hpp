//
// Created by nhyarlathotep on 24/01/19.
//

#pragma once

#include <map>
#include "FieldValue.hpp"

namespace ZiApi {
    struct KeyCaseInsensitive : public std::binary_function<std::string, std::string, bool> {
        bool operator()(const std::string &s1, const std::string &s2) const {
            return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), [](char a, char b) { return std::tolower(a) < std::tolower(b); });
        }
    };

    /**
     * @note RFC2616, section 4.2 says: "Field names are case-insensitive."
     * The keys "Key" "key" "KEY" will be the same
     */
    using HttpHeader = std::map<std::string, FieldValue, KeyCaseInsensitive>;
}