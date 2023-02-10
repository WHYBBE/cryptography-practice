#include <string>
#include <iostream>

#include "caesar_analyzer.h"
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

    auto x = CP::CaesarAnalyzer("khoor, zruog");
    x.brute_force();
    x.count_alphabet();
    x.count_words();
}

