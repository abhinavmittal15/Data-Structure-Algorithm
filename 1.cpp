#include <iostream>
#include <string>
#include <algorithm>

std::string maxOdd(std::string s) {
    int countOne = std::count(s.begin(), s.end(), '1');
    if (countOne == 0) {
        return "-1";
    }
    return std::string(countOne - 1, '1') + std::string(s.length() - countOne + 1, '0');
}

int main() {
    std::string binary = "0101";
    std::cout << "Maximum odd binary number: " << maxOdd(binary) << std::endl;
    return 0;
}