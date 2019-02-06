//
// Created by nhyarlathotep on 30/01/19.
//

#include <string>
#include <iostream>
#include "FieldValue.hpp"

int main() {
    ZiApi::FieldValue integer(10);
    ZiApi::FieldValue string(std::string("Hello world"));                   //use of std::string else ZiApi::FieldValue(bool) is called

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

    ZiApi::FieldValue::ValueList list;

    list.emplace_back(666);                                                 //Calls ZiApi::FieldValue(int)
    list.emplace_back(std::string("Dessert > all"));                        //Calls ZiApi::FieldValue(std::string)
    list.emplace_back(1.5);                                                 //Calls ZiApi::FieldValue(double)

    ZiApi::FieldValue listContainer(std::move(list));                       //Put the list in field

    const auto &genericList = std::get<ZiApi::FieldValue::ValueList>(listContainer.getValue());

    std::cout << "Size : "<< genericList.size() << std::endl;               //Size : 3
    for (auto &it : genericList) {
        auto &tmp = it.getValue();
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