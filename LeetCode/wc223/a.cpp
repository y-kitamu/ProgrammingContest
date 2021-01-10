#include <bits/stdc++.h>


class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        std::vector<int> orig(encoded.size() + 1);
        orig[0] = first;
        for (int i = 0; i < encoded.size(); i++) {
            orig[i + 1] = encoded[i] ^ orig[i];
        }
        return orig;
    }
};


int main() {

}
