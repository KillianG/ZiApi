//
// Created by nhyarlathotep on 31/01/19.
//

#include <iostream>
#include "MyFieldValue.hpp"
#include "MyHttpRequest.hpp"

int main() {
    MyHttpRequest request;

    auto &header = request.getHeader();                                     //Get the request's header

    header["Host"] = std::make_shared<MyValue>("127.0.0.1:4242");
    header.emplace(std::make_pair("Connection", std::make_shared<MyValue>("keep-alive")));

    MyValue::ValueList list;
    list.push_back(std::make_shared<MyValue>("text/html"));
    list.push_back(std::make_shared<MyValue>("application/xhtml+xml"));
    list.push_back(std::make_shared<MyValue>("application/xml"));

    header["Accept"] = std::make_shared<MyValue>(std::move(list));          //Set the field "Accept" with a list

    for (auto &it : header) {                                               //Displays fields
        const auto &tmp = it.second->getValue();
        if (std::holds_alternative<std::string>(tmp))
            std::cout << it.first << " : " << std::get<std::string>(tmp) << std::endl;
        else if (std::holds_alternative<MyValue::ValueList>(tmp)) {
            std::cout << it.first << " : [";
            for (const auto &field : std::get<MyValue::ValueList>(tmp)) {
                std::cout << " " << std::get<std::string>(field->getValue());
            }
            std::cout << " ]" << std::endl;
        }
    }

    request.setMethod(Http::Request::MethodType::GET);                      //Sets the request's method
    request.setUri("/home/index.html");                                     //Sets the request's uri
    request.setHttpVersion(1, 1);                                           //Sets the request's versions
}