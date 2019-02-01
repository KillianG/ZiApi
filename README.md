## ZiApi

API for Zia Epitech 2021

![Language](https://img.shields.io/github/languages/top/KillianG/ZiApi.svg?style=flat)
[![Documentation](https://img.shields.io/badge/docs-doxygen-blue.svg?style=flat)](https://killiang.github.io/)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](https://github.com/KillianG/ZiApi/blob/master/LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/KillianG/ZiApi.svg?style=flat)](https://github.com/KillianG/ZiApi/issues)
[![GitHub Issues closed](https://img.shields.io/github/issues-closed-raw/KillianG/ZiApi.svg?style=flat)](https://github.com/KillianG/ZiApi/issues?utf8=%E2%9C%93&q=is%3Aissue+is%3Aclosed)
![Last commit](https://img.shields.io/github/last-commit/KillianG/ZiApi.svg?style=flat)
[![GitHub Stars](https://img.shields.io/github/stars/KillianG/ZiApi.svg?style=social)](https://github.com/KillianG/ZiApi)

- [Contact](#contact)
- [Integration](#integration)
  - [CMake](#cmake)
- [Examples](#examples)  
  - [Module](#module)
  - [Request](#request)
  - [Logger](#logger)
- [Links](#links)
- [License](#license)
- [Contributors](#Contributors)

## Contact
If you have questions regarding the library, I would like to invite you to [open an issue at GitHub](https://github.com/KillianG/ZiApi/issues/new). Please describe your request, problem, or question as detailed as possible. Opening an issue at GitHub allows other users and contributors to this library to collaborate. If you have a look at the [closed issues](https://github.com/KillianG/ZiApi/issues?q=is%3Aissue+is%3Aclosed), you will see that we react quite timely in most cases.

Only if your request would contain confidential information, please [send us an email](mailto:nathan@lebon.epitech.eu).

## Integration
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

### Module
Assume you want to create your Module object

```c++
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
```

## Links
- [**CMake**](https://cmake.org) for build automation
- [**Doxygen**](http://www.doxygen.nl/) to generate [documentation](https://killiang.github.io/)
- [**Cppreference**](https://en.cppreference.com/w/)
- [**RFC 2616**](https://www.ietf.org/rfc/rfc2616.txt)


## License
<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The class is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2019 Killian Gardahaut

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: 

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Contributors
[KillianG](https://github.com/KillianG)

[Nhyarlathotep](https://github.com/nhyarlathotep)