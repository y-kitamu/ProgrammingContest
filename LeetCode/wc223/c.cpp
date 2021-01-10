#include <bits/stdc++.h>

class Solution {
public:
    int minimumHammingDistance(std::vector<int>& source,
                               std::vector<int>& target,
                               std::vector<std::vector<int>>& allowedSwaps) {
        int N = source.size();
        std::vector<int> roots(N);
        for (int i = 0; i < N; i++) {
            roots[i] = i;
        }

        auto find_root = [&roots] (int idx) {
            std::vector<int> indices;
            while (roots[idx] != idx) {
                indices.emplace_back(idx);
                idx = roots[idx];
            }
            for (auto i : indices) {
                roots[i] = idx;
            }
            return idx;
        };

        for (auto vec : allowedSwaps) {
            auto lhs = find_root(vec[0]);
            auto rhs = find_root(vec[1]);
            roots[rhs] = lhs;
        }

        std::map<int, std::map<int, int>> src, dst;
        for (int i = 0; i < N; i++) {
            int root = find_root(roots[i]);
            if (src[root].find(source[i]) == src[root].end()) {
                src[root][source[i]] = 0;
            }
            if (dst[root].find(target[i]) == dst[root].end()) {
                dst[root][source[i]] = 0;
            }
            src[root][source[i]]++;
            dst[root][target[i]]++;
        }

        int cnt = 0;
        for (auto ut : src) {
            auto lhs = ut.second;
            auto rhs = dst[ut.first];
            for (auto pair : lhs) {
                if (rhs.find(pair.first) == rhs.end()) {
                    continue;
                }
                cnt += std::min(pair.second, rhs[pair.first]);
            }
        }
        return N - cnt;
    }
};


int main() {

}
