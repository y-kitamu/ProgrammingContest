#include <bits/stdc++.h>

class Solution {
public:
    std::string findLexSmallestString(std::string s, int a, int b) {
        std::string min_str = s;
        int offset = s.length() - b;
        if (b % 2 == 0) {
            offset++;
        }
        for (int i = 0; i <= s.length(); i++) {
            std::string next_str = s;
            for (int j = 0; j < 10; j++) {
                s = add_a(s, a);
                if (compare(s, min_str)) {
                    min_str = s;
                }
                if (next_str[offset] > s[offset]) {
                    next_str = s;
                }
            }
            s = rotate(next_str, b);
        }
        return min_str;
    }

    std::string add_a(std::string s, int a) {
        for (int i = 1; i < s.length(); i += 2) {
            s[i] += a;
            if (s[i] > '9') {
                s[i] -= 10;
            }
        }
        return s;
    }

    std::string rotate(std::string s, int b) {
        std::string rotated = s;
        for (int i = 0; i < s.length(); i++) {
            int idx = i - b;
            if (idx < 0) {
                idx += s.length();
            }
            rotated[i] = s[idx];
        }
        return rotated;
    }

    bool compare(std::string lhs, std::string rhs) {
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] < rhs[i]) {
                return true;
            } else if (lhs[i] > rhs[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::string s = "43987654";
    int a = 7, b = 3;
    std::cout << Solution().findLexSmallestString(s, a, b) << std::endl;
}
