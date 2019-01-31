//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include "HttpRequest.hpp"

class MyHttpRequest : public ZiApi::HttpRequest {
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

    void setUri(const std::string &newUri) override { _uri = newUri; }

    const std::string &getUri() const override { return _uri; }

    void setMethod(MethodType newMethod) override { _method = newMethod; }

    MethodType getMethod() const override { return _method; }
};