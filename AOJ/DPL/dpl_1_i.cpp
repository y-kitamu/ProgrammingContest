#include <bits/stdc++.h>

template <class T, class Compare = std::greater<T>>
std::vector<T> knapsack_solver(T W, const std::vector<T>& values, const std::vector<T>& weights,
                               const std::vector<T>& maxes, const T& INF,
                               const Compare& comp = Compare()) {
    std::vector<T> dp(W + 1, INF);
    dp[0] = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < weights[i]; j++) {
            std::deque<T> deq, deqv;
            for (int k = 0; k * weights[i] + j <= W; k++) {
                int idx = k * weights[i] + j;
                T val = dp[idx] - values[i] * k;
                if (dp[idx] != INF) {
                    while (!deqv.empty() && comp(val, deqv.back())) {
                        deq.pop_back();
                        deqv.pop_back();
                    }
                    deq.push_back(k);
                    deqv.push_back(val);
                }

                while (!deq.empty() && deq.front() + maxes[i] < k) {
                    deq.pop_front();
                    deqv.pop_front();
                }

                if (!deq.empty()) {
                    dp[idx] = deqv.front() + values[i] * k;
                }
            }
        }
    }
    return dp;
}


template <class T, class Compare = std::greater<T>>
std::vector<int> index_sort(const std::vector<T>& vals, const std::vector<T>& weights,
                            Compare comp = Compare()) {
    std::vector<int> idx_vec(vals.size());
    std::iota(idx_vec.begin(), idx_vec.end(), 0);

    std::stable_sort(idx_vec.begin(), idx_vec.end(), [&vals, &weights, &comp](auto& lhs, auto& rhs) {
        return comp(vals[lhs] * weights[rhs], vals[rhs] * weights[lhs]);
    });
    return idx_vec;
}


int main() {
    long long int N, W;
    std::cin >> N >> W;

    std::vector<long long int> values(N), weights(N), maxes(N);
    for (int i = 0; i < N; i++) {
        std::cin >> values[i] >> weights[i] >> maxes[i];
    }

    auto v_max = *max_element(values.begin(), values.end());
    if (v_max == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<long long int> ma(N);
    std::vector<long long int> mb(N);

    for (int i = 0; i < N; i++) {
        ma[i] = std::min(maxes[i], v_max - 1);
        mb[i] = maxes[i] - ma[i];
    }

    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += values[i] * ma[i];
    }

    auto sorted = index_sort(values, weights);

    long long int max_val = 0;
    auto dp = knapsack_solver(sum, weights, values, ma, (long long int)1e9, std::less<>());
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] > W || dp[i] == 1e9) {
            continue;
        }
        long long int res = W - dp[i], cost = i;
        if (res < 0) {
            continue;
        }
        // std::cout << cost << " , " << res << " " << std::endl;
        for (auto idx : sorted) {
            int cnt = std::min(mb[idx], res / weights[idx]);
            cost += cnt * values[idx];
            res -= cnt * weights[idx];
            if (res == 0) {
                break;
            }
        }
        max_val = std::max(max_val, cost);
    }
    // std::cout << std::endl;
    std::cout << max_val << std::endl;
}
