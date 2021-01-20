#include <bits/stdc++.h>


int main() {
    int N, L;
    std::cin >> N >> L;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::multiset<int> set;
    for (int i = 0; i < L; i++) {
        set.insert(a[i]);
    }

    for (int i = L; i < N; i++) {
        int val = *set.lower_bound(0);
        std::cout << val << " ";
        auto itr = set.find(a[i - L]);
        set.erase(itr);
        set.insert(a[i]);
    }

    std::cout << *set.lower_bound(0) << std::endl;
}
