/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-15 21:09:38
 */
#include <bits/stdc++.h>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<int> vals;
    int i = 0;
    while (i < N) {
        while (i < N && S[i] != 'A') {
            i++;
        }
        if (i == N) {
            break;
        }
        int cnt_a = 0, cnt_c = 0;
        while (i < N && S[i] == 'A') {
            i++;
            cnt_a++;
        }
        if (i == N) {
            break;
        }
        if (S[i] != 'R') {
            continue;
        }
        i++;
        while (i < N && S[i] == 'C') {
            i++;
            cnt_c++;
        }
        if (cnt_a > 0 && cnt_c > 0) {
            // std::cout << cnt_a << " , " << cnt_c << std::endl;
            vals.push_back(std::min(cnt_a, cnt_c));  //
        }
    }
    std::sort(vals.begin(), vals.end());
    if (vals.size() == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // for (auto& val : vals) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;
    // std::cout << vals.size() << std::endl;


    int ans = 0;
    int idx = std::distance(vals.begin(), std::upper_bound(vals.begin(), vals.end(), 1));
    for (int i = 0; i < vals.size(); i++) {
        if (idx < vals.size()) {
            ans++;
            vals[idx]--;
            if (vals[idx] == 1) {
                idx++;
            }
        }
        if (vals[i] > 0) {
            ans++;
        }
        if (idx <= i) {
            idx = i + 1;
        }
    }

    std::cout << ans << std::endl;
}
