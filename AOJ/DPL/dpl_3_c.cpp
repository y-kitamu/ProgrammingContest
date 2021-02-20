#include <bits/stdc++.h>


long long int solve(std::vector<long long int> h) {
    int n = h.size();
    long long int max = 0;


    std::stack<long long int> val_stack, idx_stack;

    auto calc_area = [&val_stack, &idx_stack](long long int right) {
        auto val = val_stack.top();
        auto left = idx_stack.top();
        val_stack.pop();
        idx_stack.pop();
        return val * (right - left);
    };

    for (int i = 0; i < n; i++) {
        while (!val_stack.empty() && val_stack.top() > h[i]) {
            max = std::max(calc_area(i), max);
        }
        if (!val_stack.empty() && val_stack.top() == h[i]) {
            continue;
        }
        val_stack.push(h[i]);
        idx_stack.push(i);
    }

    while (!val_stack.empty()) {
        max = std::max(calc_area(n), max);
    }
    return max;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> h(N);
    for (int i = 0; i < N; i++) {
        std::cin >> h[i];
    }

    auto compare = [](auto& lhs, auto& rhs) { return lhs.first < rhs.first; };
    std::priority_queue<std::pair<long long int, long long int>,
                        std::vector<std::pair<long long int, long long int>>, decltype(compare)>
        que{compare};

    long long int max = 0;
    for (int i = 0; i < N; i++) {
        long long int idx = i;
        while (!que.empty() && que.top().first >= h[i]) {
            auto top = que.top();
            que.pop();
            max = std::max((i - top.second) * top.first, max);
            idx = std::min(idx, top.second);
        }
        que.push(std::make_pair(h[i], idx));
    }

    while (!que.empty()) {
        auto top = que.top();
        que.pop();
        max = std::max((N - top.second) * top.first, max);
    }

    std::cout << max << std::endl;
}
