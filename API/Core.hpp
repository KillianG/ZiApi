//
// Created by nhyarlathotep on 29/01/19.
//

#pragma once

#include <memory>
#include "Config.hpp"
#include "Network.hpp"
#include "ModuleManager.hpp"

namespace ZiApi {
    /**
     * @brief Server's core
     *
     * @note The Core will automatly binds the Network and the ModuleManager
     *
     * Usage example :
     * @include MyCore.hpp
     */
    class Core {
    public:
        Core(std::shared_ptr<Config> &&config, std::shared_ptr<Network> &&network, std::shared_ptr<ModuleManager> &&moduleMgr)
        : _config(config), _networkMgr(network), _moduleMgr(moduleMgr) {
            _networkMgr->setPipelineHandler([this](Http::Request &request, Http::Response &response) {
                _moduleMgr->runPipeline(request, response);
            });
        }

        virtual ~Core() = default;

        virtual void run(int ac, char **av) = 0;

        virtual const std::shared_ptr<Config> &getConfig() const = 0;

        virtual std::shared_ptr<ModuleManager> &getModuleMgr() = 0;

    protected:
        std::shared_ptr<ZiApi::Config> _config;
        std::shared_ptr<ZiApi::Network> _networkMgr;
        std::shared_ptr<ZiApi::ModuleManager> _moduleMgr;
    };
}

/**
* MyConfig.hpp : @include MyConfig.hpp
* MyNetwork.hpp : @include MyNetwork.hpp
* MyModuleManager.hpp : @include MyModuleManager.hpp
* MyCore.hpp : @include MyCore.hpp
* Output : @include MyServer.output
* MyServer.cpp : @example MyServer.cpp *
*/