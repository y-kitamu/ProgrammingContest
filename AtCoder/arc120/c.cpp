#include <bits/stdc++.h>


class BIT {
  public:
    BIT(int n) {
        max = n;
        data = std::vector<int>(max + 1, 0);
    }

    void add(int a, int w) {
        for (int x = a; x <= max; x += x & -x) {
            data[x] += w;
        }
    }

    long long int sum(int a) {
        int res = 0;
        for (int x = a; x > 0; x -= x & -x) {
            res += data[x];
        }
        return res;
    }

    int max;
    std::vector<int> data;
};


int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] += i;
    }
    std::map<int, std::vector<int>> map;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        val += i;
        map[val].emplace_back(i);
    }

    std::vector<int> sa(N);
    for (int i = 0; i < N; i++) {
        if (map[A[i]].size() == 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        sa[i] = map[A[i]][0];
        map[A[i]].erase(map[A[i]].begin());
    }

    long long int ans = 0;
    BIT bit(N);
    for (int i = 0; i < N; i++) {
        ans += i - bit.sum(sa[i] + 1);
        bit.add(sa[i] + 1, 1);
    }
    std::cout << ans << std::endl;
}
