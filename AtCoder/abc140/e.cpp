#include <bits/stdc++.h>

long long int solve_naive(int N, std::vector<long long int>& P) {
    long long int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        std::set<long long int> set;
        set.insert(P[i]);
        for (int j = i + 1; j < N; j++) {
            set.insert(P[j]);
            auto itr = set.end();
            itr--;
            sum += *(--itr);
        }
    }
    return sum;
}


template <class T, class Compare = decltype(std::greater<T>())>
std::vector<size_t> sort_index(std::vector<T>& vals, Compare comp = std::greater<T>()) {
    std::vector<size_t> indices(vals.size());
    iota(indices.begin(), indices.end(), 1);

    stable_sort(indices.begin(), indices.end(),
                [&vals, &comp](auto lhs, auto rhs) { return comp(vals[lhs - 1], vals[rhs - 1]); });
    return indices;
}


long long int solve(int N, std::vector<long long int>& P) {
    long long int sum = 0;

    auto indices = sort_index(P);
    std::multiset<int> set;
    set.insert(0);
    set.insert(0);
    set.insert(N + 1);
    set.insert(N + 1);
    std::vector<int> w(N), x(N), y(N), z(N);
    for (int i = 0; i < N; i++) {
        auto itr = set.lower_bound(indices[i]);
        long long int max_idx0 = *(itr);
        long long int max_idx1 = *(++itr);
        itr--;
        long long int min_idx0 = *(--itr);
        long long int min_idx1 = *(--itr);

        sum += (max_idx1 - max_idx0) * (indices[i] - min_idx0) * (N - i);
        sum += (max_idx0 - indices[i]) * (min_idx0 - min_idx1) * (N - i);
        set.insert(indices[i]);
    }

    return sum;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    auto sum = solve(N, P);

    std::cout << sum << std::endl;
}
