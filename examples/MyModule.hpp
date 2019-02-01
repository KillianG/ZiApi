//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include <iostream>
#include "Core.hpp"
#include "Module.hpp"

class SSLModule : public ZiApi::Module {
public:
    SSLModule(ZiApi::Core &core) {
        _name = "SSL";
        int priority = 0;                                       //The module priority can be set in the config file
        core.getModuleMgr()->addToPipeline(priority, _name);    //Add the module to the processing list
    };

    const std::string &getName() const noexcept override { return _name; }

    bool handle(Http::Request &request, Http::Response &response) override {    //Do your things here
        std::cout << __PRETTY_FUNCTION__ << std::endl;                          //virtual bool SSLModule::handle(Http::Request&, Http::Response&)
        response.setStatusCode(Http::Response::StatusCode::OK);
        response.setStatusMessage("OK");
        return true;
    }
};

extern "C" {
std::unique_ptr<ZiApi::Module> createModule(ZiApi::Core &core) {    //It will be called by the dl functions
    return std::make_unique<SSLModule>(core);                       //Gives the Core to the module if needed
};
}