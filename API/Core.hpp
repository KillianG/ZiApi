//
// Created by nhyarlathotep on 29/01/19.
//

#pragma once

#include <memory>
#include <functional>
#include "Config.hpp"
#include "ModuleManager.hpp"

#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

namespace ZiApi {
    class Network {
    public:
        virtual void run() = 0;

        /**
         * @brief
         * @param callback
         *
         * @code
         * network.setHandler([&moduleMgr] (const auto &request) {
         *      moduleMgr.runPipeline(request);
         * }
         * @endcode
         */
        virtual void setHandler(std::function<void(std::unique_ptr<HttpRequest>)> &&callback) = 0;

    protected:
        virtual void pollRequest() = 0;

        virtual bool send(HttpRequest &request, HttpResponse &response) = 0;

        std::function<void(HttpRequest &request, HttpResponse &response)> _pipelineCallback;
    };
}

namespace ZiApi {
    class Core {
    public:
        virtual void run(int ac, char **av) = 0;

        virtual const std::unique_ptr<Config> &getConfig() const = 0;

        virtual std::unique_ptr<Network> &getNetwork() = 0;

        virtual std::unique_ptr<ModuleManager> &getModuleMgr() = 0;
    };
}