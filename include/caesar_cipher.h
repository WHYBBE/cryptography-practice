#pragma once

#include <string>
#include <cctype>
#include <iostream>

namespace CP {

template<int Offset = 3, bool Number = false>
requires (Offset >= 0 && Offset <= 25)
class Caesar {
private:
    std::string str;
public:
    constexpr Caesar(std::string && source):str(std::move(source)) {}

    constexpr std::string encode()
    requires (Number == true) {
        std::string res;
        res.reserve(str.size() * 2);
        for(auto c:str) {
            if(!std::isalpha(c)) {
                res += c;
                continue;
            }
            auto A = std::islower(c) ? 'a' : 'A';
            auto n = (c - A + Offset) % 26 + 1;
            res += n / 10 + '0', res += n % 10 + '0';
        }
        return res;
    }

    constexpr std::string decode()
    requires (Number == true) {
        int size = str.size();
        std::string res;
        res.reserve(size / 2);
        for(int i = 0; i < size; i++) {
            if(!std::isdigit(str[i])) {
                res += str[i];
                continue;
            }
            if(i + 1 == size) break;
            if(!std::isdigit(str[i + 1])) break;
            res += ((str[i] - '0') * 10
                 + (str[i + 1] - '0') - 1 + 26 - Offset) % 26
                 + 'A';
            i++;
        }
        return res;
    }

    template<bool PlusOrMinus>
    constexpr std::string transform() {
        auto X = PlusOrMinus ? Offset : 26 - Offset;
        for(auto &c:str) {
            if(!std::isalpha(c)) continue;
            auto A = std::islower(c) ? 'a' : 'A';
            c = (c - A + X) % 26 + A;
        }
        return std::move(str);
    }

    constexpr std::string encode() {
        return std::move(transform<true>());
    }

    constexpr std::string decode() {
        return std::move(transform<false>());
    }
};

using Repeat = Caesar<0>;
using Avocat = Caesar<10>;
using AK = Avocat;
using ROT13 = Caesar<13>;
using Cassis = Caesar<21, true>;          // -5
using K6 = Cassis;
using Cassette = Caesar<22, true>;        // -4
using K7 = Cassette;

}

