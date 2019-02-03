//
// Created by killian on 23/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include "Request.hpp"
#include "Response.hpp"

namespace ZiApi {
    class Core;
    /**
     * @brief Server's Module
     *
     * Usage example :
     * @include MyModule.hpp
     */
    class Module {
    public:
        /**
         * @brief Gets the current name
         */
        virtual const std::string &getName() const noexcept = 0;

        /**
         * @brief The module compute the request and response (it's up to you)
         * @param[in/out] request sended by the client
         * @param[in/out] response reply sent to the client
         * @return
         * * `true` breaks the chain
         *
         * * `false` continue the chain
         */
        virtual bool handle(Http::Request &request, Http::Response &response) = 0;

    protected:
        std::string _name;          ///< The module's name
    };
}

extern "C" {
    /**
     * @brief Create a Module
     * @param[in] core The server Core
     * @warning This function must be defined in each dynamic library
     */
    std::unique_ptr<ZiApi::Module> createModule(ZiApi::Core &core);
}