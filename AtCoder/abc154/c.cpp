#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::set<int> set;
    bool flag = true;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        flag &= set.find(a) == set.end();
        set.insert(a);
    }

    if (flag) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
