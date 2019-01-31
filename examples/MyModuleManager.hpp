//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include <iostream>
#include "ModuleManager.hpp"

class MyModuleMgr : public ZiApi::ModuleManager {
public:
    bool load(const std::string &modulePath, ZiApi::Core &core) override {
        auto mod = createModule(core);
        std::cout << "Load Module ["<< mod->getName() << "]" << std::endl;              //Load Module [SSL]
        _modules[mod->getName()] = std::move(mod);
        return false;
    }

    bool unLoad(const std::string &moduleName) override {
        /*It is up to you*/
        return false;
    }

    bool isLoaded(const std::string &moduleName) override {
        /*It is up to you*/
        return false;
    }

    bool addToPipeline(size_t importance, const std::string &name) override {
        return _pipeline.emplace(std::make_pair(importance, name)).second;              //Emplace the module in the processing list
    }

    bool runPipeline(Http::Request &request, Http::Response &response) override {
        std::cout << __PRETTY_FUNCTION__ << std::endl;                                  //virtual bool SSLModule::handle(Http::Request&, Http::Response&)
        for (auto &it : _pipeline) {
            if (_modules[it.second]->handle(request, response))                         //Calls the module handle function
                break;
        }
        return true;
    }
};