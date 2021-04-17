#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<int> ans;
    int ai = 0, bi = 0;
    while (ai != N || bi != M) {
        if (ai == N) {
            ans.emplace_back(B[bi]);
            bi++;
            continue;
        }
        if (bi == M) {
            ans.emplace_back(A[ai]);
            ai++;
            continue;
        }

        if (A[ai] < B[bi]) {
            ans.emplace_back(A[ai]);
            ai++;
        } else if (A[ai] > B[bi]) {
            ans.emplace_back(B[bi]);
            bi++;
        } else {
            ai++, bi++;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i];
        if (i < ans.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
