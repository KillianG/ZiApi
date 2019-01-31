//
// Created by nhyarlathotep on 29/01/19.
//

#pragma once

#include <memory>
#include "Config.hpp"
#include "ModuleManager.hpp"

#include "Network.hpp"

namespace ZiApi {
    class Core {
    public:
        Core(std::shared_ptr<Config> &&config, std::shared_ptr<Network> &&network, std::shared_ptr<ModuleManager> &&moduleMgr)
        : _config(config), _networkMgr(network), _moduleMgr(moduleMgr) {
            _networkMgr->setPipelineHandler([this](Http::Request &request, Http::Response &response) {
                _moduleMgr->runPipeline(request, response);
            });
        }

        virtual void run(int ac, char **av) = 0;

        virtual const std::shared_ptr<Config> &getConfig() const = 0;

        virtual std::shared_ptr<ModuleManager> &getModuleMgr() = 0;

    protected:
        std::shared_ptr<ZiApi::Config> _config;
        std::shared_ptr<ZiApi::Network> _networkMgr;
        std::shared_ptr<ZiApi::ModuleManager> _moduleMgr;
    };
}