#include <bits/stdc++.h>


int bubbleSort(std::vector<int>& vec) {
    int count = 0;

    int N = vec.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i -1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                count++;
            }
        }
    }
    return count;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N - N / 2), B(N / 2);
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            std::cin >> A[i / 2];
        } else {
            std::cin >> B[i / 2];
        }
    }

    std::sort(A.begin(), A.end(), [](auto lhs, auto rhs) { return lhs < rhs; });
    std::sort(B.begin(), B.end(), [](auto lhs, auto rhs) { return lhs < rhs; });

    std::vector<int> merge(N);
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            merge[i] = A[i / 2];
        } else {
            merge[i] = B[i / 2];
        }
    }

    int count = bubbleSort(merge);
    std::cout << count << std::endl;
}
