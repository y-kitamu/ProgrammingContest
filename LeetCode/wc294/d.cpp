/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-22 11:51:01
 */
#include <bits/stdc++.h>


class Solution {
    void print_vec(std::vector<long long int>& vec) {
        for (auto& v : vec) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

  public:
    int totalStrength(std::vector<int>& strength) {
        long long int mod = 1e9 + 7;
        int N = strength.size();
        std::vector<long long int> sum0(N + 1, 0);
        std::vector<long long int> sum1(N + 1, 0);
        for (int i = 0; i < N; i++) {
            sum0[i + 1] = (sum0[i] + strength[i]) % mod;
        }
        for (int i = 0; i < N; i++) {
            sum1[i + 1] = (sum1[i] + sum0[i + 1]) % mod;
        }

        std::vector<long long int> rsum0(N + 1, 0);
        std::vector<long long int> rsum1(N + 1, 0);
        for (int i = N; i > 0; i--) {
            rsum0[i - 1] = (rsum0[i] + strength[i - 1]) % mod;
        }
        for (int i = N; i > 0; i--) {
            rsum1[i - 1] = (rsum1[i] + rsum0[i - 1]) % mod;
        }

        {
            print_vec(sum0);
            print_vec(sum1);
            print_vec(rsum0);
            print_vec(rsum1);
        }
        std::vector<int> indices(N);
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(),
                  [&strength](auto& lhs, auto& rhs) { return strength[lhs] < strength[rhs]; });
        std::set<int> used;
        used.insert(-1);
        used.insert(N);

        long long int ans = 0;
        for (int i = 0; i < N; i++) {
            long long int idx = indices[i];
            long long int total = 0;

            auto upper = used.upper_bound(idx);
            long long int max = *upper - 1;
            long long int min = *(--upper) + 1;
            total += (idx - min + 1) * (max - idx + 1) * (long long int)strength[idx] % mod;
            long long int lhs = ((idx - min + 1) * sum0[idx] - (sum1[idx] - sum1[min])) % mod;
            total += (lhs * (max - idx + 1) % mod);
            long long int rhs =
                ((max - idx + 1) * rsum0[idx + 1] - (rsum1[idx + 1] - rsum1[max + 1])) % mod;
            total += (rhs * (idx - min + 1) % mod);
            ans = (ans + total * strength[idx]) % mod;
            {
                std::cout << idx << " , " << strength[idx] << " , " << min << " , " << max << ", " << ans
                          << ", lhs = " << lhs << ", rhs = " << rhs << std::endl;
            }
            used.insert(idx);
        }
        return ans;
    }
};

int main() {}
