#include <bits/stdc++.h>

constexpr static int MAX = 1000000007;
std::vector<long long int> pow2s(33, -1);

int pow2(int N) {
    if (pow2s[N] != -1) {
        return pow2s[N];
    }
    if (N % 2 == 0) {
        pow2s[N] = pow2(N / 2) * pow2(N / 2) % MAX;
    } else {
        pow2s[N] = pow2(N / 2) * pow2(N / 2)  * 2  % MAX;
    }
    return pow2s[N];
}


int main() {
    int N;
    std::cin >> N;

    pow2s[0] = 1;
    pow2s[1] = 2;

    std::map<std::pair<long long int, long long int>, int> map;
    for (int i = 0; i < N; i++) {
        long long int a, b;
        std::cin >> a >> b;
        long long int g = std::gcd(a, b);
        a = a / g;
        b = b / g;
        if (a < 0) {
            a *= -1;
            b *= -1;
        }
        auto p = std::make_pair(a, b);
        if (map.find(p) == map.end()) {
            map[p] = 0;
        }
        map[p]++;
    }

    long long int no_counter = 0;
    long long int factor = 1;
    for (auto&& m : map) {
        if (m.second == 0) {
            continue;
        }
        auto counter = std::make_pair(m.first.second, m.first.first * -1);
        if (counter.first < 0) {
            counter.first *= -1;
            counter.second *= -1;
        }
        if (map.find(counter) == map.end()) {
            no_counter += m.second;
        } else {
            factor *= (pow2(m.second) + pow2(map[counter]) - 1);
            map[counter] = 0;
        }
    }

    std::cout << (pow2(no_counter) * factor - 1) % MAX << std::endl;
}
