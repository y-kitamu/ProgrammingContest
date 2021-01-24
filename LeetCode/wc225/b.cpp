#include <bits/stdc++.h>


class Solution {
  public:
    int minCharacters(std::string a, std::string b) {
        std::vector<int> cnt_a(26, 0), cnt_b(26, 0);
        for (auto c : a) {
            cnt_a[c - 'a']++;
        }
        for (auto c : b) {
            cnt_b[c - 'a']++;
        }

        auto calc_max = [](std::vector<int> vec) {
            int max = 0;
            for (auto val : vec) {
                max = std::max(val, max);
            }
            return max;
        };

        int max_a = calc_max(cnt_a);
        int max_b = calc_max(cnt_b);

        int min_ops = a.size() - max_a + b.size() - max_b;

        auto calc_ops = [](std::vector<int> less, std::vector<int> more) {
            int ops_less = 0, ops_more = 0;
            for (auto val : less) {
                ops_less += val;
            }
            int min = ops_less + ops_less;
            for (int i = 0; i < 25; i++) {
                ops_less -= less[i];
                ops_more += more[i];
                min = std::min(ops_less + ops_more, min);
            }
            return min;
        };

        min_ops = std::min(min_ops, calc_ops(cnt_a, cnt_b));
        min_ops = std::min(min_ops, calc_ops(cnt_b, cnt_a));
        return min_ops;
    }
};


int main() {}
