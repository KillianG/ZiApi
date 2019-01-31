//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include <functional>
#include "Request.hpp"
#include "Response.hpp"

namespace ZiApi {
    /**
     * @brief Server's sockets handler
     */
    class Network {
    public:
        /**
         * @brief Launchs the server's sockets
         */
        virtual void run() = 0;

        /**
         * @brief Called when a request is received
         *
         * Runs the _pipelineRunCallBack to execute the module's processing list
         * @code
         * Http::Request request;
         * Http::Response response;
         *
         * _pipelineRunCallBack(request, response); //The request and response will be set by the modules
         *
         * send(response, ...);                     //Send the response to the client (it is up to you)
         * @endcode
         */
        virtual void pollRequest() = 0;

        /**
         * @brief Sets ModuleManager::runPipeline(...) as callback function
         * @warning It is already set by the Core on construction
         */
        void setPipelineHandler(std::function<void(Http::Request &request, Http::Response &response)> &&callback) { _pipelineRunCallBack = callback; };

    protected:
        std::function<void(Http::Request &request, Http::Response &response)> _pipelineRunCallBack;     ///<Callback on the module's processing list
    };
}