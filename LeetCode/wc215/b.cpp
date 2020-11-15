#include <bits/stdc++.h>


class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        std::vector<int> count1(26, 0), count2(26, 0);
        for (auto c : word1) {
            count1[c - 'a']++;
        }
        for (auto c : word2) {
            count2[c - 'a']++;
        }

        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (count1[i] > 0) {
                flag &= count2[i] > 0;
            }
            if (count2[i] > 0) {
                flag &= count1[i] > 0;
            }
            if (count1[i] == 0) {
                flag &= count2[i] == 0;
            }
            if (count2[i] == 0) {
                flag &= count1[i] == 0;
            }
        }

        std::sort(count1.begin(), count1.end());
        std::sort(count2.begin(), count2.end());
        for (int i = 0; i < 26; i++) {
            flag &= count1[i] == count2[i];
        }
        return flag;
    }
};

int main() {

}
