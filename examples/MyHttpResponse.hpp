//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include "Response.hpp"

class MyHttpResponse : public Http::Response {
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