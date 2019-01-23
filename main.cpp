#include <iostream>


#include <ZiExcept.hpp>

int main() {
    try {
        throw (ZiApi::ZiExcept("wsh renaud"));
    } catch (ZiApi::ZiExcept &e) {
        std::cout << e.what() << std::endl;
    }
}