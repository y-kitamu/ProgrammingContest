#include <iostream>


int merge(long *A, int left, int mid, int right, int cnt) {
    int n1 = mid - left;
    int n2 = right - mid;

    long L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1 + 1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2 + 1; i++) {
        R[i] = A[mid + i];
    }

    L[n1] = 1e9 + 1;
    R[n2] = 1e9 + 1;

    int i = 0, j = 0;

    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
    return cnt;
}

int mergeSort(long *A, int left, int right, int cnt) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        cnt = mergeSort(A, left, mid, cnt);
        cnt = mergeSort(A, mid, right, cnt);
        cnt = merge(A, left, mid, right, cnt);
    }
    return cnt;
}


int main() {
    int n;
    std::cin >> n;

    long S[n];
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    int cnt = 0;
    cnt = mergeSort(S, 0, n, cnt);

    for (int i = 0; i < n - 1; i++) {
        std::cout << S[i] << " ";
    }
    std::cout << S[n - 1] << std::endl;
    std::cout << cnt << std::endl;;
}
