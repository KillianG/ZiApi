//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include "HttpHeader.hpp"

namespace ZiApi {
    struct HttpRequest {
        enum class Type {
            Unknown, Options, Get, Head, Post, Put, Delete, Trace, Connect
        };

        HttpHeader header;
    };
}