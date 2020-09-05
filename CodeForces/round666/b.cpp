#include <bits/stdc++.h>


int main() {
    int n;
    std::cin >> n;
    std::vector<long long int> vals(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vals[i];
    }

    std::sort(vals.begin(), vals.end(), [](auto lhs, auto rhs) {return lhs < rhs;});
    long long int min_val = 1e14;
    long long int min_sum = 1e14;
    long long int seed = 1;
    while (true) {
        long long int sum = 0;
        long long int power = 1;
        bool flag = false;
        for (int j = 0; j < n; j++) {
            sum += std::abs(vals[j] - power);
            power *= seed;
            if (j < n - 1 && power > min_val) {
                flag = true;
                break;
            }
        }
        if (flag || sum > min_sum) {
            break;
        }
        min_sum = sum;
        seed++;
    }
    std::cout << min_sum << std::endl;
}
