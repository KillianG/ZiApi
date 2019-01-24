//
// Created by killian on 23/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef PROJECT_AMODULE_HPP
#define PROJECT_AMODULE_HPP

#include <unordered_map>
#include <cstdarg>
#include "IModule.hpp"
#include "ZiExcept.hpp"

namespace ZiApi {
    class AModule: public IModule {
    public:

        AModule(std::string path, std::string name, size_t nbModules, AModule *A...) : _isLoaded(false), name(std::move(name)) {
            va_list args;
            va_start(args, A);

            linkedModules.insert(std::make_pair<const std::string, AModule*>(A->getName(), std::move(A)));

            for (auto i = 0; i < nbModules-1; i++) {
                auto mod = va_arg(args, AModule*);
                linkedModules.insert(std::make_pair<const std::string, AModule*>(mod->getName(), std::move(mod)));
            }
            va_end(args);
        }

        virtual ~AModule() = default;

        AModule(std::string path, std::string name) : _isLoaded(false), name(std::move(name)) {}

        void unLoad() override { _isLoaded = false; }
        bool isLoaded() final { return _isLoaded; }
        std::string getName() const override { return name; }

    protected:
        bool _isLoaded;
        std::string name;
        std::unordered_map<std::string, AModule*> linkedModules;
    };
}

#else
namespace ZiApi {
    class AModule;
}

#endif //PROJECT_AMODULE_HPP
