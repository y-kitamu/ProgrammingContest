#include <bits/stdc++.h>

class Solution {
  public:
    bool splitString(std::string s) {
        std::vector<long long int> vals(s.length());
        for (int i = 0; i < s.length(); i++) {
            vals[i] = (int)(s[i] - '0');
        }

        std::vector<long long int> vec(20, 0);
        for (int i = 1; i < 1 << (s.length() - 1); i++) {
            std::fill(vec.begin(), vec.end(), 0);
            vec[0] = vals[0];
            int idx = 0;
            for (int j = 0; j < s.length() - 1; j++) {
                if (i & (1 << j)) {
                    idx++;
                }
                vec[idx] = 10 * vec[idx] + vals[j + 1];
                if (vec[idx] > 1e11) {
                    break;
                }
            }

            if (idx > 0) {
                bool flag = true;
                for (int j = 1; j <= idx; j++) {
                    flag &= (vec[j - 1] - vec[j]) == 1;
                }
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {}
