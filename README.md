## ZiApi

API for Zia Epitech 2021

![Language](https://img.shields.io/github/languages/top/KillianG/ZiApi.svg?style=flat)
[![Documentation](https://img.shields.io/badge/docs-doxygen-blue.svg?style=flat)](https://killiang.github.io/)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](https://github.com/KillianG/ZiApi/blob/master/LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/KillianG/ZiApi.svg?style=flat)](https://github.com/KillianG/ZiApi/issues)
[![GitHub Issues closed](https://img.shields.io/github/issues-closed-raw/KillianG/ZiApi.svg?style=flat)](https://github.com/KillianG/ZiApi/issues?utf8=%E2%9C%93&q=is%3Aissue+is%3Aclosed)
![Last commit](https://img.shields.io/github/last-commit/KillianG/ZiApi.svg?style=flat)
[![GitHub Stars](https://img.shields.io/github/stars/KillianG/ZiApi.svg?style=social)](https://github.com/KillianG/ZiApi)

- [Integration](#integration)
  - [CMake](#cmake)
- [Examples](#examples)  
- [Contributors](#Contributors)

## Contact
If you have questions regarding the library, I would like to invite you to [open an issue at GitHub](https://github.com/KillianG/ZiApi/issues/new). Please describe your request, problem, or question as detailed as possible. Opening an issue at GitHub allows other users and contributors to this library to collaborate. If you have a look at the [closed issues](https://github.com/KillianG/ZiApi/issues?q=is%3Aissue+is%3Aclosed), you will see that we react quite timely in most cases.

Only if your request would contain confidential information, please [send us an email](mailto:nathan@lebon.epitech.eu).

### Integration
**How to add ZiApi to your project :**
```bash
git clone git@github.com:KillianG/ZiApi.git
```
### CMake
It is necessary to compiles with  C++17 flags.
```cmake
include_directories(ZiApi/API ZiApi/API/HTTP)
```

## Examples

Beside the examples below, you may want to check the [documentation](https://killiang.github.io/). 
All [example files](https://github.com/KillianG/ZiApi/tree/master/examples) can be compiled and executed on their own.

Assume you want to create your Module object

```c++
class SSLModule : public ZiApi::Module {
public:
    SSLModule(ZiApi::Core &core) {
        _name = "SSL";
        core.getModuleMgr()->addToPipeline(0, _name);                       //Add the module to the processing list
    };

    const std::string &getName() const noexcept override { return _name; }

    bool handle(Http::Request &request, Http::Response &response) override {
        std::cout << __PRETTY_FUNCTION__ << std::endl;                      //virtual bool SSLModule::handle(Http::Request&, Http::Response&)
        response.setStatusCode(Http::Response::StatusCode::OK);
        response.setStatusMessage("OK");
        return true;
    }
};

extern "C" {
std::unique_ptr<ZiApi::Module> createModule(ZiApi::Core &core) {
    return std::make_unique<SSLModule>(core);                               //Gives the Core to the module if needed
};
}
```







​![](./docs/Http_namespace.png)
![](./docs/ZiApi_namespace.png)

## Contributors
[KillianG](https://github.com/KillianG)

[Nhyarlathotep](https://github.com/nhyarlathotep)