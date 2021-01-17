#include <bits/stdc++.h>



int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> counts(N, 0);
    int num = 0, left = 0, right = 0, min = N + 1;
    for (;;) {
        while (num < K) {
            if (counts[a[right]] == 0 && a[right] < K) {
                num++;
            }
            counts[a[right]]++;
            right++;
            if (num == K || right == N) {
                break;
            }
        }
        if (num == K){
            min = std::min(min, right - left);
        }
        while (num == K) {
            counts[a[left]]--;
            if (counts[a[left]] == 0 && a[left] < K) {
                min = std::min(min, right - left);
                left++;
                num--;
                break;
            }
            left++;
        }
        if (right == N) {
            break;
        }
    }
    if (min == N + 1) {
        min = 0;
    }
    std::cout << min << std::endl;
}
