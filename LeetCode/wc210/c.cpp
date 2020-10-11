#include <bits/stdc++.h>

class Solution {
public:
    bool checkPalindromeFormation(std::string a, std::string b) {
        return checkImple(a, b) || checkImple(b, a);
    }

    bool checkImple(std::string a, std::string b) {
        int size = a.length();
        bool flag = true;
        bool flag_a = true;
        bool flag_b = true;
        for (int i = 0; i < size / 2; i++) {
            if (flag && a[i] == b[size - i - 1]) {
            } else  {
                if (flag_a && a[i] == a[size - i - 1]) {
                } else {
                    flag_a = false;
                }
                if (flag_b && b[i] == b[size - i - 1]) {
                } else {
                    flag_b = false;
                }
                if (!flag_a && !flag_b) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {

}
