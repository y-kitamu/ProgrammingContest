#include <bits/stdc++.h>

class Solution {
  public:
    void print_vec(std::vector<int>& cnt) {
        for (auto& val : cnt) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    int longestBeautifulSubstring(std::string word) {
        int max = 0;
        std::vector<int> cnt(5, 0);
        for (int i = 0; i < word.size(); i++) {
            print_vec(cnt);
            switch (word[i]) {
                case 'a':
                    if (cnt[1] > 0 || cnt[2] > 0 || cnt[3] > 0 || cnt[4] > 0) {
                        std::fill(cnt.begin(), cnt.end(), 0);
                    }
                    cnt[0]++;
                    break;
                case 'e':
                    if (cnt[0] == 0 || cnt[2] > 0 || cnt[3] > 0 || cnt[4] > 0) {
                        std::fill(cnt.begin(), cnt.end(), 0);
                    } else {
                        cnt[1]++;
                    }
                    break;
                case 'i':
                    if (cnt[0] == 0 || cnt[1] == 0 || cnt[3] > 0 || cnt[4] > 0) {
                        std::fill(cnt.begin(), cnt.end(), 0);
                    } else {
                        cnt[2]++;
                    }
                    break;
                case 'o':
                    if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0 || cnt[4] > 0) {
                        std::fill(cnt.begin(), cnt.end(), 0);
                    } else {
                        cnt[3]++;
                    }
                    break;
                case 'u':
                    if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0) {
                        std::fill(cnt.begin(), cnt.end(), 0);
                    } else {
                        cnt[4]++;
                        int sum = 0;
                        for (auto& c : cnt) {
                            sum += c;
                        }
                        max = std::max(sum, max);
                    }
                    break;
            }
        }
        return max;
    }
};


int main() {}
