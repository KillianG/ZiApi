//
// Created by nhyarlathotep on 31/01/19.
//

#include <iostream>
#include "MyHttpRequest.hpp"

int main() {
    MyHttpRequest request;

    auto &header = request.getHeader();                                     //Get the request's header

    header["Host"] = std::string("127.0.0.1:4242");
    header.emplace(std::make_pair("Connection", std::string("keep-alive")));

    ZiApi::FieldValue::ValueList list;
    list.emplace_back(std::string("text/html"));
    list.emplace_back(std::string("application/xhtml+xml"));
    list.emplace_back(std::string("application/xml"));

    header["Accept"] = std::move(list);                                     //Set the field "Accept" with a list

    for (auto &it : header) {                                               //Displays fields
        const auto &tmp = it.second.getValue();
        if (std::holds_alternative<std::string>(tmp))
            std::cout << it.first << " : " << std::get<std::string>(tmp) << std::endl;
        else if (std::holds_alternative<ZiApi::FieldValue::ValueList>(tmp)) {
            std::cout << it.first << " : [";
            for (const auto &field : std::get<ZiApi::FieldValue::ValueList>(tmp)) {
                std::cout << " " << std::get<std::string>(field.getValue());
            }
            std::cout << " ]" << std::endl;
        }
    }

    request.setMethod(Http::Request::MethodType::GET);                      //Sets the request's method
    request.setUri("/home/index.html");                                     //Sets the request's uri
    request.setHttpVersion(1, 1);                                           //Sets the request's versions
}