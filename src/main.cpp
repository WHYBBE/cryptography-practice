#include <string>
#include <iostream>

#include "caesar_cipher.h"

int main() {
    auto input = std::string("hello, world");
    auto expect = std::string("khoor, zruog");
    auto output = CP::Caesar(std::move(input)).encode();
    auto res = expect == output;
    std::cout << "\"" << output
              << "\" equals \""
              << expect << "\" : "
              << std::boolalpha
              << res << std::endl;
}

