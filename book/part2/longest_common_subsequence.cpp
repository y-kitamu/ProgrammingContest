#include <iostream>
#include <string>
#include <vector>


class Subsequence {
public:
    Subsequence(std::string a, std::string b) : a(a), b(b) {
        memo = std::vector<std::vector<int>>(a.length(), std::vector<int>(b.length(), -1));
    }
    
    int calcLongest(int idx_a, int idx_b) {
        if (memo[idx_a][idx_b] == -1) {
            if (a[idx_a] == b[idx_b]) {
                if (idx_a > 0 && idx_b > 0) {
                    memo[idx_a][idx_b] = calcLongest(idx_a - 1, idx_b - 1) + 1;
                } else {
                    memo[idx_a][idx_b] = 1;
                }
            } else {
                int x0 = idx_a > 0 ? calcLongest(idx_a - 1, idx_b) : 0;
                int x1 = idx_b > 0 ? calcLongest(idx_a, idx_b - 1) : 0;
                memo[idx_a][idx_b] = std::max(x0, x1);
            }
        } 
        return memo[idx_a][idx_b];
    }

    std::vector<std::vector<int>> memo;
    std::string a, b;
};


int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string a, b;
        std::cin >> a >> b;
        
        Subsequence seq(a, b);
        int res = seq.calcLongest(a.length() - 1, b.length() - 1);
        std::cout << res << std::endl;
    }
}
