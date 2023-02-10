#pragma once

#include <array>
#include <string_view>
#include <string>
#include <iostream>
#include <unordered_map>
#include <cctype>
#include <algorithm>

namespace CP {

class CaesarAnalyzer {
private:
    std::string_view secret;
public:
    constexpr CaesarAnalyzer(std::string_view secret):secret(secret) {}

    void brute_force() {
        std::cout << "\n";
        std::string str(secret);
        auto size = secret.size();
        std::cout << "  0 | " << str << " \n";
        std::cout << "----+";
        std::cout << std::string(size + 2, '-') << "\n";
        for(int i = 1; i < 26; i++) {
            for(auto &c:str) {
                if(!std::isalpha(c)) continue;
                auto A = std::islower(c) ? 'a' : 'A';
                c = (c - A + 1) % 26 + A;
            }
            std::cout << " ";
            std::cout.width(2);
            std::cout << i << " | " << str << " \n";
        }
    }

    void count_words() {
        if(secret.size() <= 200) {
            std::cout << "\n[warning]: too short to analyse words\n";
            return;
        }

        std::unordered_map<std::string_view, int> word_counter{0};
    }

    void count_alphabet() {
        if(secret.size() <= 200) {
            std::cout << "\n[warning]: too short to analyse alphabet\n";
            return;
        }

        std::array<int, 26> alphabet_upper{0};
        std::array<int, 26> alphabet_lower{0};
        std::array<int, 26> alphabet_total{0};
        int counter_lower = 0, counter_upper = 0, counter_tatal;
        for(auto x:secret) {
            if(std::islower(x)) alphabet_lower[x - 'a']++, counter_lower++;
            else if(std::isupper(x)) alphabet_upper[x - 'A']++, counter_upper++;
        }

        for(int i = 0; i < 26; i++)
            alphabet_total[i] = alphabet_lower[i] + alphabet_upper[i];
        counter_tatal = counter_lower + counter_upper;

        std::cout << "\n";
        for(int i = 0; i < 26; i++) {
            std::cout.flags(std::ios::left);

            std::cout << "  " << to_char(i + 'a') << " = ";
            std::cout.width(6);
            std::cout << alphabet_lower[i];

            std::cout << "|  " << to_char(i + 'A') << " = ";
            std::cout.width(6);
            std::cout << alphabet_upper[i];

            std::cout << "|  " << to_char(i + 'a')
                << ',' << to_char(i + 'A') << " = ";
            std::cout.width(6);
            
            std::cout << alphabet_total[i] << "\n";
        }

        print_table(alphabet_lower, counter_lower, 0);
        print_table(alphabet_upper, counter_upper, 1);
        print_table(alphabet_total, counter_tatal, 2);
    }
private:
    char to_char(char c) {
        return static_cast<char>(c);
    }

    void print_table(std::array<int, 26>& alphabet, int counter, int type) {
        auto level = counter == 0 ?
            0 : *std::ranges::max_element(alphabet) * 1.0 / counter / 8;
        std::cout << "\n";
        for(int i = 8; i > 0; i--) {
            std::cout.precision(3);
            std::cout.flags(std::cout.fixed);
            auto value = level * i;
            std::cout.width(4);
            if(value != 0) std::cout << value << " |";
            else std::cout << "    - |";
            for(int j = 0; j < 26; j++) {
                std::cout << " ";
                if(alphabet[j] >= value * counter && value != 0) std::cout << 'I';
                else std::cout << " ";
            }
            std::cout << "\n";
        }
        std::cout.unsetf(std::cout.fixed);
        std::cout <<  "    0 *";
        for(int i = 0; i < 26; i++)
            std::cout << "--";
        std::cout <<  "\n       ";
        char c = type == 1 ? 'A' : 'a';
        for(int i = 0; i < 26; i++)
            std::cout << " " << to_char(i + c);
        if(type == 2) {
            c = c - 'a' + 'A';
            std::cout << "\n       ";
            for(int i = 0; i < 26; i++)
                std::cout << " " << to_char(i + c);
        }
        std::cout << "\n";
    }
};

}
