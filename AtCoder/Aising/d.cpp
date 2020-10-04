#include <bits/stdc++.h>


std::vector<int> map(500000, 0);


class TestClass {
  public:
    void print_func() {
        std::cout << "test" << std::endl;
    }
};


int func(int val) {
    if (val == 0) {
        map[val] = 0;
        return map[val];
    }
    if (map[val] != 0) {
        return map[val];
    }
    std::bitset<20> bs(val);
    int count = bs.count();
    map[val] = func(val % count) + 1;
    return map[val];
}


int main() {
    int N;
    std::string X;
    std::cin >> N >> X;

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (X[i] == '1') {
            count++;
        }
    }

    int c_m = std::max(count - 1, 1);
    int c_p = count + 1;
    std::vector<int> mod_cm(N, 1 % c_m), mod_cp(N, 1 % c_p);

    map[1] = 1;
    map[2] = 1;

    int sum_m = 0, sum_p = 0;
    if (X[N - 1] == '1') {
        sum_m = mod_cm[N - 1];
        sum_p = mod_cp[N - 1];
    }
    for (int i = N - 2; i >= 0; i--) {
        mod_cm[i] = mod_cm[i + 1] * 2 % c_m;
        mod_cp[i] = mod_cp[i + 1] * 2 % c_p;
        if (X[i] == '1') {
            sum_m = (sum_m + mod_cm[i]) % c_m;
            sum_p = (sum_p + mod_cp[i]) % c_p;
        }
    }

    for (int i = 0; i < N; i++) {
        int val;
        if (X[i] == '1') {
            if (count == 1) {
                std::cout << 0 << std::endl;
                continue;
            }
            val = (sum_m - mod_cm[i] + c_m) % c_m;
        } else {
            val = (sum_p + mod_cp[i]) % c_p;
        }
        std::cout << func(val) + 1 << std::endl;
    }
}
