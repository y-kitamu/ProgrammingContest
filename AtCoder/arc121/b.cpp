#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> rs, gs, bs;
    int rc = 0, gc = 0, bc = 0;
    for (int i = 0; i < N * 2; i++) {
        long long int val;
        char c;
        std::cin >> val >> c;
        if (c == 'R') {
            rs.emplace_back(val);
            rc++;
        } else if (c == 'G') {
            gs.emplace_back(val);
            gc++;
        } else if (c == 'B') {
            bs.emplace_back(val);
            bc++;
        }
    }

    std::sort(rs.begin(), rs.end());
    std::sort(gs.begin(), gs.end());
    std::sort(bs.begin(), bs.end());

    auto calc_min_diff = [](auto& od0, auto& od1) {
        long long int min = 2e15;
        for (auto& val : od0) {
            auto itr = std::upper_bound(od1.begin(), od1.end(), val);
            if (itr != od1.end()) {
                min = std::min(min, std::abs(val - *itr));
            }
            if (itr != od1.begin()) {
                itr--;
                min = std::min(min, std::abs(val - *itr));
            }
        }
        return min;
    };

    long long int rg = calc_min_diff(rs, gs);
    long long int gb = calc_min_diff(gs, bs);
    long long int br = calc_min_diff(bs, rs);

    if (rc % 2 == 0 && gc % 2 == 0 && bc % 2 == 0) {
        std::cout << 0 << std::endl;
    } else if (rc % 2 == 0) {
        std::cout << std::min(gb, rg + br) << std::endl;
    } else if (gc % 2 == 0) {
        std::cout << std::min(br, rg + gb) << std::endl;
    } else if (bc % 2 == 0) {
        std::cout << std::min(rg, gb + br) << std::endl;
    }
}
