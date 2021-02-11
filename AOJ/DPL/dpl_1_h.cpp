#include <bits/stdc++.h>


int binarySearch(long long int weight, int lhs, int rhs,
                 std::vector<std::pair<long long int, long long int>> &vals) {
    if (lhs == rhs) {
        return lhs;
    }

    int mid = (lhs + rhs + 1) / 2;
    if (weight == vals[mid].second) {
        return mid;
    }
    if (weight > vals[mid].second) {
        return binarySearch(weight, mid, rhs, vals);
    }
    return binarySearch(weight, lhs, mid - 1, vals);
}


int main() {
    long long int N, W;
    std::cin >> N >> W;

    std::vector<std::vector<long long int>> left(N / 2, std::vector<long long int>(2));
    std::vector<std::vector<long long int>> right(N - N / 2, std::vector<long long int>(2));

    for (int i = 0; i < N / 2; i++) {
        std::cin >> left[i][0] >> left[i][1];
    }

    for (int i = 0; i < N - N / 2; i++) {
        std::cin >> right[i][0] >> right[i][1];
    }

    std::vector<std::pair<long long int, long long int>> lvals(1 << N / 2);
    for (int i = 0; i < 1 << N / 2; i++) {
        long long int val = 0, weight = 0;
        for (int j = 0; j < N / 2; j++) {
            if (i >> j & 1) {
                val += left[j][0];
                weight += left[j][1];
            }
        }
        lvals[i] = std::make_pair(val, weight);
    }

    auto compare = [](auto &lhs, auto &rhs) {
        if (lhs.second < rhs.second) {
            return true;
        } else if (lhs.second > rhs.second) {
            return false;
        } else {
            return lhs.first > rhs.first;
        }
    };
    std::sort(lvals.begin(), lvals.end(), compare);

    long long int max = lvals[0].first;
    for (int i = 0; i < 1 << N / 2; i++) {
        max = std::max(lvals[i].first, max);
        lvals[i].first = max;
        // std::cout << lvals[i].first << " , " << lvals[i].second << std::endl;
    }

    long long int max_val = 0;
    for (int i = 0; i < 1 << (N - N / 2); i++) {
        long long int val = 0, weight = 0;
        for (int j = 0; j < N - N / 2; j++) {
            if (i >> j & 1) {
                val += right[j][0];
                weight += right[j][1];
            }
        }
        int idx = binarySearch(W - weight, 0, lvals.size() - 1, lvals);
        // std::cout << val << " , " << weight << " , " << idx << " , " << lvals[idx].first << " , "
        //           << lvals[idx].second << std::endl;
        if (idx >= 0) {
            val += lvals[idx].first;
        }
        if (weight + lvals[idx].second <= W) {
            max_val = std::max(max_val, val);
        }
    }

    std::cout << max_val << std::endl;
}
