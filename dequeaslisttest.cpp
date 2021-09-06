#include <iostream>
#include <string>
#include "URLHistory.hpp"

int main() {
    URLHistory history;
    std::string input;

    do {
        std::getline(std::cin, input);
    } while (history.Parse(std::move(input)));

    return 0;
}
