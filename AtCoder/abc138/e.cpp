#include <bits/stdc++.h>


int binarySearch(int val, int left, int right, const std::vector<int>& vec) {
    if (left == right) {
        return left;
    }
    int mid = (left + right) / 2;
    if (vec[mid] == val) {
        return mid;
    }
    if (val < vec[mid]) {
        return binarySearch(val, left, mid, vec);
    }
    return binarySearch(val, mid + 1, right, vec);
}


int main() {
    std::string s, t;
    std::cin >> t >> s;

    std::vector<std::vector<int>> map(26);
    for (int i = 0; i < t.size(); i++) {
        map[(int)(t[i] - 'a')].emplace_back(i);
    }

    long long int count = 0;
    int current_idx = 0;
    for (auto c : s) {
        int val = (int)(c - 'a');
        if (map[val].size() == 0) {
            count = -1;
            break;
        }
        int idx = binarySearch(current_idx, 0, map[val].size(), map[val]);
        if (idx == map[val].size()) {
            count += t.size() - current_idx + map[val][0] + 1;
            current_idx = map[val][0] + 1;
        } else {
            count += map[val][idx] - current_idx + 1;
            current_idx = map[val][idx] + 1;
        }
        // std::cout << c << " , " << count << " , " << current_idx << " , " << idx << std::endl;
    }
    std::cout << count << std::endl;
}
