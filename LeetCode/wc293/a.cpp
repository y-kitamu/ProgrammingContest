/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-15 11:29:33
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<std::string> removeAnagrams(std::vector<std::string>& words) {
        auto anag = [](std::string& w) {
            std::map<char, int> map;
            for (auto& c : w) {
                map[c]++;
            }
            return map;
        };

        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i < words.size(); i++) {
                bool is_same = true;
                auto lhs = anag(words[i - 1]);
                auto rhs = anag(words[i]);
                for (auto& pair : lhs) {
                    if (rhs[pair.first] != pair.second) {
                        is_same = false;
                        break;
                    }
                }
                for (auto& pair : rhs) {
                    if (lhs[pair.first] != pair.second) {
                        is_same = false;
                        break;
                    }
                }
                if (is_same) {
                    words.erase(words.begin() + i);
                    flag = true;
                    break;
                }
            }
        }
        return words;
    }
};


int main() {}
