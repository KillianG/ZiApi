
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

#include "HttpHeader.hpp"

class myFieldValue : public ZiApi::FieldValue {
public:
    myFieldValue(int value) { _value = value; }
    myFieldValue(const std::string &value) { _value = value; }

    const ValueVarient &getValue() const noexcept override {
        return _value;
    }

    FieldValue &operator=(const ValueVarient &other) noexcept override {
        _value = other;
        return *this;
    }
};

int main() {
    ZiApi::HttpHeader header;

    header["int"] = std::make_unique<myFieldValue>(10);
    header["string"] = std::make_unique<myFieldValue>("Salut");

    std::cout << std::get<int>(header["int"]->getValue()) << std::endl;
    std::cout << std::get<std::string>(header["string"]->getValue()) << std::endl;
}