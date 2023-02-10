#pragma once

#include <string>
#include <cctype>

namespace CP {

template<int N = 3>
requires (N >= 0 && N <= 25)
class Caesar {
private:
    std::string str;
public:
    constexpr Caesar(std::string && source):str(std::move(source)) {}

    constexpr const std::string& encode() {
        for(auto &c:str)
          if(std::islower(c)) c = (c - 'a' + N) % 26 + 'a';
          else if(std::isupper(c)) c = (c - 'A' + N) % 26 + 'a';
        return str;
    }

    constexpr const std::string& decode() {
        for(auto &c:str)
          if(std::islower(c)) c = (c - 'a' - N) % 26 + 'a';
          else if(std::isupper(c)) c = (c - 'A' - N) % 26 + 'a';
        return str;
    }
};

}

