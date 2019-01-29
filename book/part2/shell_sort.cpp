#include <iostream>
#include <vector>

int insertSort(int *A, int N, int g) {
    int cnt = 0;
    for (int i = g; i < N; i++) {
        int j = i - g;
        while (j >= 0 && A[j] > A[j + g]) {
            std::swap(A[j], A[j + g]);
            j -= g;
            cnt++;
        }
    }
    return cnt;
}


int shellSort(int *A, int N, int *g, int m) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += insertSort(A, N, g[i]);
    }
    return cnt;
}


int main(int argc, char ** argv) {
    int N;
    std::cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> vg;
    for (int i = 1; i <= N; i *= 2) {
        vg.push_back(i);
    }

    int g[vg.size()];
    for (int i = 0; i < (int)vg.size(); i++) {
        g[i] = vg[vg.size() - 1 - i];
    }

    int cnt = shellSort(arr, N, g, vg.size());

    std::cout << vg.size() << std::endl;
    for (int i = 0; i < (int)vg.size(); i++) {
        std::cout << g[i];
        if (i != (int)vg.size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }

    std::cout << cnt << std::endl;

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << std::endl;
    }
}
