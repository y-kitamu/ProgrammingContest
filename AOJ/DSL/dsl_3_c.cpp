#include <bits/stdc++.h>

long long int count(const std::vector<long long int>& sum_a, long long int val) {
    long long int sum = 0;
    int right = 0;
    for (int left = 0; left < sum_a.size(); left++) {
        while (right < sum_a.size() && sum_a[right] - sum_a[left] <= val) {
            right++;
        }
        sum += right - left - 1;
    }
    return sum;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<long long int> sum_a(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        std::cin >> sum_a[i];
        sum_a[i] += sum_a[i - 1];
    }

    for (int i = 0; i < Q; i++) {
        long long int val;
        std::cin >> val;
        std::cout << count(sum_a, val) << std::endl;
    }
}
