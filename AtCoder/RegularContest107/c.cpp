#include <bits/stdc++.h>

long long int MOD = 998244353;


long long int mod_permutation(int val) {
    long long int sum = 1;
    for (int i = 1; i <= val; i++) {
        sum = (sum * i) % MOD;
    }
    return sum;
}


long long int calcLinkNum(bool is_row, const int N, const int K,
                          const std::vector<std::vector<int>> &matrix) {
    auto check_rows = [&matrix, &N, &K, &is_row](int lhs, int rhs) {
        for (int i = 0; i < N; i++) {
            if (is_row) {
                if (matrix[i][lhs] + matrix[i][rhs] > K) {
                    return false;
                }
            } else {
                if (matrix[lhs][i] + matrix[rhs][i] > K) {
                    return false;
                }
            }
        }
        return true;
    };

    std::vector<std::vector<int>> linked_list(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (check_rows(i, j)) {
                linked_list[i].emplace_back(j);
                linked_list[j].emplace_back(i);
            }
        }
    }

    std::vector<int> root(N);
    for (int i = 0 ; i < N; i++) {
        root[i] = i;
    }
    auto find_root = [&root] (int idx) {
        std::vector<int> indices;
        while (idx != root[idx]) {
            indices.emplace_back(idx);
            idx = root[idx];
        }
        for (auto val : indices) {
            root[val] = idx;
        }
        return idx;
    };

    for (int i = 0; i < N; i++) {
        for (auto idx : linked_list[i]) {
            int r_i = find_root(i);
            int r_j = find_root(idx);
            root[r_j] = r_i;
        }
    }
    std::map<int, int> cnts;
    for (int i = 0; i < N; i++) {
        int r = find_root(i);
        if (cnts.find(r) == cnts.end()) {
            cnts[r] = 0;
        }
        cnts[r]++;
    }

    long long int sum = 1;
    for (auto pair : cnts) {
        sum = mod_permutation(pair.second) * sum % MOD;
    }
    return sum;
}


int main() {

    int N, K;
    std::cin >> N >> K;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << (calcLinkNum(true, N, K, matrix) * calcLinkNum(false, N, K, matrix)) % MOD << std::endl;
}
