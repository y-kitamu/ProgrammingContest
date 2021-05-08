#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }


    int min = 1, max = 1e9;
    while (min != max) {
        int mid = (min + max) / 2;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += (A[i] + mid - 1) / mid - 1;
        }
        if (cnt <= K) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    std::cout << min << std::endl;
}
