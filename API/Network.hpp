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
     *
     * @note Must be multi-threaded to handle multiple clients at the same time
     *
     * Usage example :
     * @include MyNetwork.hpp
     */
    class Network {
    public:
        virtual ~Network() = default;

        /**
         * @brief Launchs the server's sockets
         */
        virtual void run() = 0;

        /**
         * @brief Called when a request is received
         *
         * Runs the Pipeline via the _runPipeline callback
         * @code
         * Http::Request request;
         * Http::Response response;
         *
         * _runPipeline(request, response);         //Runs the pipeline. The request and response will be set by the modules
         *
         * send(response, ...);                     //Send the response to the client (it's up to you)
         * @endcode
         */
        virtual void pollRequest() = 0;

        /**
         * @brief Sets ModuleManager::runPipeline as callback function
         * @warning It is already set by the Core on construction
         */
        void setPipelineHandler(std::function<void(Http::Request &request, Http::Response &response)> &&callback) { _runPipeline = callback; };

    protected:
        std::function<void(Http::Request &request, Http::Response &response)> _runPipeline;     ///<Callback on the module's processing list
    };
}