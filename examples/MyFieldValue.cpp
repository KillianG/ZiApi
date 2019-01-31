//
// Created by nhyarlathotep on 30/01/19.
//

#include <string>
#include <iostream>
#include "MyFieldValue.hpp"

int main() {
    MyValue integer(10);
    MyValue string("Hello world");

    integer = 42;                                                           //operator = ValueVariant is implicitly constructed

    std::cout << std::get<int>(integer.getValue()) << std::endl;            //42

    try {
        std::cout << std::get<int>(string.getValue()) << std::endl;
    } catch (const std::bad_variant_access &e) {
        std::cout << e.what() << std::endl;                                 //Unexpected index
    }

    if (std::holds_alternative<std::string>(string.getValue())) {
        std::cout << std::get<std::string>(string.getValue()) << std::endl; //Hello world
    }

    MyValue::ValueList list;

    list.push_back(std::make_shared<MyValue>(666));
    list.push_back(std::make_shared<MyValue>("Dessert > all"));
    list.push_back(std::make_shared<MyValue>(1.5));

    MyValue listContainer(std::move(list));                                 //Put the list in field

    const auto &genericList = std::get<MyValue::ValueList>(listContainer.getValue());

    std::cout << "Size : "<< genericList.size() << std::endl;               //Size : 3
    for (auto &it : genericList) {
        auto &tmp = it->getValue();
        if (std::holds_alternative<int>(tmp)) {
            std::cout << std::get<int>(tmp) << std::endl;
        } else if (std::holds_alternative<std::string>(tmp)) {
            std::cout << std::get<std::string>(tmp) << std::endl;
        } else if (std::holds_alternative<double>(tmp)) {
            std::cout << std::get<double>(tmp) << std::endl;
        }
    }
    return 0;
}