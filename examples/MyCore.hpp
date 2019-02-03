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
    MyCore() : Core(std::make_shared<MyConfig>(), std::make_shared<MyNetwork>(), std::make_shared<MyModuleMgr>()) {
        /*It's up to you*/
        _moduleMgr->load("./Path", *this);          //Load a Module
    }

    void run(int ac, char **av) override {
        /*It's up to you*/
        _networkMgr->run();                         //Launchs the sockets
    }

    const std::shared_ptr<ZiApi::Config> &getConfig() const override { return _config; }

    std::shared_ptr<ZiApi::ModuleManager> &getModuleMgr() override { return _moduleMgr; }
};