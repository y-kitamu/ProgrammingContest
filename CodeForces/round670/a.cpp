#include <bits/stdc++.h>


int maximumMexSplit(std::vector<int>& A) {
    std::vector<int> count(101, 0);
    for (auto&& val : A) {
        count[val]++;
    }

    int first = -1, second = -1;
    for (int i = 0; i < count.size(); i++) {
        if (first == -1) {
            if (count[i] == 1) {
                first = i;
            } else if (count[i] == 0) {
                first = i;
                second = i;
                break;
            }
            continue;
        }
        if (count[i] == 0) {
            second = i;
            break;
        }
    }
    if (second == -1) {
        second = 101;
    }
    return first + second;
}


int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int j = 0; j < n; j++) {
            std::cin >> A[j];
        }
        std::cout << maximumMexSplit(A) << std::endl;
    }
}
