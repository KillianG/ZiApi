//
// Created by killian on 23/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

namespace ZiApi {
    class Core;

    class Module {
    public:
        virtual const std::string &getName() const noexcept = 0;

        virtual bool handle(HttpRequest &request, HttpResponse &response) = 0;

    protected:
        std::string _name;
    };
}

extern "C" {
    std::unique_ptr<ZiApi::Module> createModule(ZiApi::Core &core);
}