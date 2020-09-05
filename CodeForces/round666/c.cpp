#include <bits/stdc++.h>


int main() {
    long long int n;
    std::cin >> n;

    std::vector<long long int> vals(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vals[i];
    }

    long long int n_left, n_right;
    if (n % 4 == 0) {
        n_left = n / 2 - 1;
        n_right = n / 2 + 1;
    } else if (n % 2 == 0) {
        n_left = std::max(n / 2 - 2, 0ll);
        n_right = n - n_left;
    } else {
        n_left = n / 2;
        n_right = n - n_left;
    }

    if (n <= 2) {
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << -vals[0] << std::endl;
        if (n == 2) {
            std::cout << 2 << " " << 2 << std::endl;
            std::cout << -vals[1] << std::endl;
        } else {
            std::cout << 1 << " " << 1 << std::endl;
            std::cout << 0 << std::endl;
        }
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<long long int> mods_left(n_left);
    for (int i = 0; i < n_left; i++) {
        long long int mod = (n_left - n * i % n_left) % n_left;
        mods_left[mod] = i;
    }

    std::vector<long long int> mods_right(n_right);
    for (int i = 0; i < n_right; i++) {
        long long int mod = (n_right - n * i % n_right) % n_right;
        mods_right[mod] = i;
    }

    std::vector<long long int> step1(n);
    for (int i = 0; i < n_left; i++) {
        long long int mod = mods_left[(n_left + vals[i] % n_left) % n_left];
        step1[i] = mod * n;
    }
    for (int i = n_left; i < n; i++){
        long long int mod = mods_right[(n_right + vals[i] % n_right) % n_right];
        step1[i] = mod * n;
    }

    std::cout << 1 << " " << n << std::endl;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            std::cout << step1[i] << " ";
        } else {
            std::cout << step1[i] << std::endl;
        }
    }

    std::cout << 1 << " " << n_left << std::endl;
    for (int i = 0; i < n_left; i++) {
        if (i < n_left - 1) {
            std::cout << - (step1[i] + vals[i]) << " ";
        } else {
            std::cout << - (step1[i] + vals[i]) << std::endl;
        }
    }

    std::cout << n_left + 1 << " " << n << std::endl;
    for (int i = n_left; i < n; i++) {
        if (i < n - 1) {
            std::cout << - (step1[i] + vals[i]) << " ";
        } else {
            std::cout << - (step1[i] + vals[i]) << std::endl;
        }
    }
}
