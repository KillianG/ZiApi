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
        virtual ~Module() = default;

        /**
         * @brief Handle function return status
         */
        enum class ModuleStatus {
            OK,         ///<The handle function is ok the process can continue
            STOP,       ///<The process has to stop due to needs of a module
            ERROR,      ///<There was an error during the module handle function
            FATAL       ///<The process has to stop due to a fatal error in the handle function
        };

        /**
         * @brief Gets the current name
         */
        virtual const std::string &getName() const noexcept = 0;

        /**
         * @brief The module compute the request and response (it's up to you)
         * @param[in/out] request sent by the client
         * @param[in/out] response reply sent to the client
         * @return The status for the processing list
         */
        virtual ModuleStatus handle(Http::Request &request, Http::Response &response) = 0;

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
