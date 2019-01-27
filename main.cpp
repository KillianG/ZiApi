
#include <AModule.hpp>

#include "Pipeline.hpp"
#include "AModule.hpp"

class SSLModule : public ZiApi::AModule {
public:
    SSLModule(std::string name) : AModule(std::move(name), 0.5f) {
    }
};

extern "C" std::unique_ptr<ZiApi::AModule> createModule() {
    return std::unique_ptr<ZiApi::AModule>(new SSLModule("SSL"));
}


#include "ZiLogger.hpp"

int main() {
}