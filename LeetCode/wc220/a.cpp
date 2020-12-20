#include <bits/stdc++.h>

class Solution {
public:
    std::string reformatNumber(std::string number) {
        std::string numbers = "";
        for (auto c : number) {
            if (c == ' ' || c == '-') {
                continue;
            }
            numbers += c;
        }
        int num = (numbers.length() - 2) / 3;
        std::string formatted = "";
        for (int i = 0; i < num; i++) {
            formatted += numbers.substr(i * 3, 3) + "-";
        }
        if (numbers.length() <= (num + 1) * 3) {
            formatted += numbers.substr(num * 3);
        } else {
            formatted += numbers.substr(num * 3, 2) + "-";
            formatted += numbers.substr(num * 3 + 2);
        }
        return formatted;
    }
};


int main() {

}
