#include <bits/stdc++.h>


int main() {
    long long int N, X, M;
    std::cin >> N >> X >> M;

    std::vector<int> seq0(M, -1), seq1(M, -1), flag(M, 0);
    int cnt0 = 0, cnt1 = 0;
    long long int sum0 = 0, sum1 = 0;
    long long int cur = X % M;
    for (;;) {
        if (flag[cur] == 1) {
            break;
        }
        seq0[cnt0] = cur;
        sum0 += cur;
        flag[cur] = 1;
        cur = (cur * cur) % M;
        cnt0++;
    }

    std::fill(flag.begin(), flag.end(), 0);
    for (;;) {
        if (flag[cur] == 1) {
            break;
        }
        seq1[cnt1] = cur;
        sum1 += cur;
        flag[cur] = 1;
        cur = (cur * cur) % M;
        cnt1++;
    }

    long long int res = 0;
    if (N <= cnt0) {
        for (int i = 0; i < N; i++) {
            res += seq0[i];
        }
    } else if (N <= cnt0 + cnt1) {
        res = sum0;
        for (int i = 0; i < N - cnt0; i++) {
            res += seq1[i];
        }
    } else {
        res = sum0 + (N - cnt0) / cnt1 * sum1;
        for (int i = 0; i < (N - cnt0) % cnt1; i++) {
            res += seq1[i];
        }
    }
    std::cout << res << std::endl;
}
