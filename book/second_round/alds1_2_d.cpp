#include <iostream>
#include <vector>


int insertionSort(int * A, int n, int g) {
    int cnt = 0;
    for (int i = g; i < n; i++) {
        int val = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > val) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = val;
    }
    return cnt;
}

void shellSort(int * A, int n) {
    int cnt = 0;

    std::vector<int> G;
    for (int h = 1;;) {
        if (h > n) break;
        G.emplace_back(h);
        h = 3 * h + 1;
    }

    int m = G.size();
    for (int i = m - 1; i >= 0; i--) {
        cnt += insertionSort(A, n, G[i]);
    }

    std::cout << m << std::endl;
    for (int i = m - 1; i > 0; i--) {
        std::cout << G[i] << " ";
    }
    std::cout << G[0] << std::endl;

    std::cout << cnt << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    shellSort(A, N);
}
