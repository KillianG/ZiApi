//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef ZIAPI_IMODULE_HPP
#define ZIAPI_IMODULE_HPP

#include <string>
#include <memory>

namespace ZiApi {
    class IModule {
    public:
        virtual ~IModule() = default;

        virtual bool isLoaded() = 0;
        virtual void unLoad() = 0;
        virtual std::string getName() const = 0;
    };
}

#else
namespace ZiApi {
    class IModule;
}
#endif //ZIAPI_IMODULE_HPP
