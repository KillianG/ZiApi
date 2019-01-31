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
        _moduleMgr->load("./Path", *this);
    }

    void run(int ac, char **av) override {
        /*It is up to you*/
        _networkMgr->run();
    }

    const std::shared_ptr<ZiApi::Config> &getConfig() const override { return _config; }

    std::shared_ptr<ZiApi::ModuleManager> &getModuleMgr() override { return _moduleMgr; }
};