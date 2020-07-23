#include <bits/stdc++.h>

int N, K;
std::vector<int> jueries;

int next(int sum, int left, int right, std::vector<int> minuses) {
    if (left + right == K || left + right == N)  {
        return sum;
    }
    int rest = K - (left + right);
    int max_sum = sum;
    if (minuses.size() >= rest) {
        std::sort(minuses.begin(), minuses.end());
        for (int i = 0; i < rest; i++) {
            max_sum -= minuses[i];
        }
    }

    int next_left = left;
    int next_sum = sum;
    std::vector<int> next_minuses = minuses;
    while (jueries[next_left] < 0) {
        if (next_left + right == K || next_left + right == N) {
            break;
        }
        next_sum += jueries[next_left];
        next_minuses.emplace_back(jueries[next_left]);
        next_left++;
    }
    int left_sum = max_sum;
    int count = next_left + right;
    if (count < K && count < N - 1) {
        next_sum += jueries[next_left++];
        next_sum = next(next_sum, next_left, right, next_minuses);
        left_sum = std::max(left_sum, next_sum);
    }

    next_sum = sum;
    int next_right = right;
    next_minuses = minuses;
    while (jueries[N - next_right - 1] < 0) {
        if (left + next_right == K || left + next_right == N) {
            break;
        }
        next_sum += jueries[N - next_right - 1];
        next_minuses.emplace_back(jueries[N - right - 1]);
        next_right++;
    }
    int right_sum = max_sum;
    count = left + next_right;
    if (count < K && count < N - 1) {
        next_sum += jueries[N - next_right - 1];
        next_right++;
        next_sum = next(next_sum, left, next_right, next_minuses);
        right_sum = std::max(next_sum, right_sum);
    }

    max_sum = std::max(max_sum, right_sum);
    return std::max(max_sum, left_sum);
}


int main() {
    std::cin >> N >> K;

    jueries = std::vector<int>(N);
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        jueries[i] = val;
    }

    std::vector<int> minuses;
    int val = next(0, 0, 0, minuses);
    std::cout << val << std::endl;
}
