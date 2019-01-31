//#include "Core.hpp"
//#include "Module.hpp"
//
//class SSLModule : public ZiApi::Module {
//public:
//    SSLModule(ZiApi::Core &core) {
//        _name = "SSL";
//        core.getModuleMgr()->addToPipeline(0, _name);
//    };
//
//    const std::string &getName() const noexcept override { return _name; }
//
//    bool handle(ZiApi::HttpRequest &, ZiApi::HttpResponse &response) override {
//        response.setStatusCode(ZiApi::HttpResponse::StatusCode::OK);
//        response.setStatusMessage("OK");
//        return true;
//    }
//};
//
//extern "C" {
//    std::unique_ptr<ZiApi::Module> createModule(ZiApi::Core &core) {
//        return std::make_unique<SSLModule>(core);
//    };
//}

//#include <iostream>
//
//class MyModuleMgr : public ZiApi::ModuleManager {
//public:
//    bool load(const std::string &modulePath, ZiApi::Core &core) override {
//        (void)modulePath;
//        std::unique_ptr<ZiApi::Module> mod = createModule(core);
//        return _modules.emplace(std::make_pair(mod->getName(), std::move(mod))).second;
//    }
//
//    bool unLoad(const std::string &) override { return false; }
//
//    bool isLoaded(const std::string &) override { return false; }
//
//    bool addToPipeline(size_t order, const std::string &name) override {
//        return _pipeline.emplace(std::make_pair(order, name)).second;
//    }
//
//    bool runPipeline(ZiApi::HttpRequest &request, ZiApi::HttpResponse &response) override {
//        for (auto &it : _pipeline) {
//            _modules[it.second]->handle(request, response);
//        }
//        return false;
//    }
//};
//
//class MyCore : public ZiApi::Core {
//public:
//    MyCore() : _moduleMgr(std::make_unique<MyModuleMgr>()){
//        _moduleMgr->load("TEST_PATH", *this);
//
//        MyRequest request;
//        MyResponse response;
//        _moduleMgr->runPipeline(request, response);
//    }
//
//    void run(int, char **) override {
//    }
//
//    const std::unique_ptr<ZiApi::Config> &getConfig() const override { return _config; }
//    std::unique_ptr<ZiApi::Network> &getNetwork() override { return _networkMgr; }
//    std::unique_ptr<ZiApi::ModuleManager> &getModuleMgr() override { return _moduleMgr; }
//
//private:
//    std::unique_ptr<ZiApi::Config> _config;
//    std::unique_ptr<ZiApi::Network> _networkMgr;
//    std::unique_ptr<ZiApi::ModuleManager> _moduleMgr;
//};

#include "HttpResponse.hpp"

class MyHttpResponse : public ZiApi::HttpResponse {
public:
    HttpHeader &getHeader() override { return _header; }

    void setBody(const std::string &newBody) override { _body = newBody; }

    const std::string &getBody() const override { return _body; }

    void setHttpVersion(uint8_t major, uint8_t minor) override {
        _versionMajor = major;
        _versionMinor = minor;
    }

    std::string getHttpVersion() const override {
        return "HTTP/" + std::to_string(_versionMajor) + "." + std::to_string(_versionMinor);
    }

    void setStatusCode(StatusCode newCode) override { _statusCode = newCode; }

    StatusCode getStatusCode() const override { return _statusCode; }

    void setStatusMessage(const std::string &newMessage) override { _statusMessage = newMessage; }

    const std::string &getStatusMessage() const override { return _statusMessage; }
};

int main() {
}