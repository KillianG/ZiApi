//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef ZIAPI_IMODULE_HPP
#define ZIAPI_IMODULE_HPP

#include <string>

namespace ZiApi {
    class IModule {
    public:
        virtual ~IModule() = default;

        virtual bool isLoaded() = 0;
        virtual void load() = 0;
        virtual void unLoad() = 0;
        virtual std::string getName() = 0;
    };
}
#endif //ZIAPI_IMODULE_HPP
