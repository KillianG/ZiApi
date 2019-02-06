//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include "Core.hpp"
#include "MyConfig.hpp"
#include "MyNetwork.hpp"
#include "MyModuleManager.hpp"

class MyCore : public ZiApi::Core {
public:
    MyCore() : Core(std::make_unique<MyConfig>(), std::make_unique<MyNetwork>(), std::make_unique<MyModuleMgr>()) {
        /* It's up to you */
        _moduleMgr->load("./Path", *this);          //Load a Module
    }

    void run(int ac, char **av) override {
        /* It's up to you */
        _networkMgr->run();                         //Launchs the sockets
    }

    const std::unique_ptr<ZiApi::Config> &getConfig() const override { return _config; }

    std::unique_ptr<ZiApi::ModuleManager> &getModuleMgr() override { return _moduleMgr; }
};