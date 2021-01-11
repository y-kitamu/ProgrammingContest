#include <bits/stdc++.h>


int main() {
    int N, S;
    std::cin >> N >> S;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    int left = 0, right = 0;
    int sum = 0;
    int length = N + 1;
    while (right < N) {
        if (sum - a[left] >= S) {
            sum -= a[left];
            left++;
        } else {
            sum += a[right];
            right++;
        }
        if (sum >= S) {
            length = std::min(length, right - left);
        }
    }

    while (sum - a[left] >= S) {
        sum -= a[left];
        left++;
        length = std::min(length, right - left);
    }

    if (length == N + 1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << length << std::endl;
    }
}
