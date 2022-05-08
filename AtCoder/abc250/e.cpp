/**
 * @file e.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-08 21:31:19
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int cnt = 0;
    int ia = 0, ib = 0;
    std::set<int> a_b, b_a, a, b;
    std::vector<int> sa(N, -1), sb(N, -1);
    while (ia < N || ib < N) {
        if (a_b.size() == 0 && b_a.size() == 0) {
            if (b.find(B[ib]) != b.end()) {
                if (a_b.size() == 0) {
                    sb[ib] = cnt;
                }
                ib++;
                continue;
            } else if (a.find(A[ia]) != a.end()) {
                if (a_b.size() == 0) {
                    sa[ia] = cnt;
                }
                ia++;
                continue;
            }
        }

        if (ib < N && a_b.size() >= b_a.size()) {
            cnt++;
            b.insert(B[ib]);
            a_b.erase(B[ib]);
            if (a.find(B[ib]) == a.end()) {
                b_a.insert(B[ib]);
            }
            if (a_b.size() == 0 && b_a.size() == 0) {
                sa[ia - 1] = cnt;
                sb[ib] = cnt;
            }
            ib++;
        } else {
            cnt++;
            a.insert(A[ia]);
            b_a.erase(A[ia]);
            if (b.find(A[ia]) == b.end()) {
                a_b.insert(A[ia]);
            }
            if (b_a.size() == 0 && a_b.size() == 0) {
                sa[ia] = cnt;
                sb[ib - 1] = cnt;
            }
            ia++;
        }
    }

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        if (sa[x] == sb[y] && sa[x] >= 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
