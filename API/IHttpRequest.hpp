//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef PROJECT_IHTTPREQUEST_HPP
#define PROJECT_IHTTPREQUEST_HPP

namespace ZiApi {
    class IHttpRequest {
        enum Type {
            Unknown, Options, Get, Head, Post, Put, Delete, Trace, Connect
        };

    };
}

#endif //PROJECT_IHTTPREQUEST_HPP
