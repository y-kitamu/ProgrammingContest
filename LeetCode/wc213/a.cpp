#include <bits/stdc++.h>


class Solution {
public:
    bool match(std::vector<int>& arr, std::vector<int>& piece, int start_idx) {
        for (int i = 0; i < piece.size(); i++) {
            if (arr[i + start_idx] != piece[i]) {
                return false;
            }
        }
        return true;
    }

    bool canFormArray(std::vector<int>& arr, std::vector<std::vector<int>>& pieces) {
        int idx = 0;
        std::sort(pieces.begin(), pieces.end(),
                  [](auto &lhs, auto &rhs) {return lhs.size() > rhs.size();});
        while (idx != arr.size()) {
            bool flag = false;
            for (int i = 0; i < pieces.size(); i++) {
                auto piece = pieces[i];
                if (match(arr, piece, idx)) {
                    idx += piece.size();
                    pieces.erase(pieces.begin() + i);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        return idx == arr.size();
    }
};


int main() {

}
