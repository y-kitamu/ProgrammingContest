#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    int cnt0 = 0, cnt1 = 0;
    
    for (auto && c : S) {
        if (c == '0') {
            if (cnt1 > 0) cnt1--;
            else cnt0++;
        } else if (c == '1') {
            if (cnt0 > 0) cnt0--;
            else cnt1++;
        }
    }
    std::cout << S.length() - cnt0 - cnt1 << std::endl;
}
