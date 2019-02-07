#include <iostream>
#include <cstring>

int bubbleSort(int *A, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                std::swap(A[j - 1], A[j]);
                cnt++;
            }
        }
    }
    return cnt;
}


long merge(int *A, int left, int right, int mid, long cnt) {
    int B[mid - left + 1], C[right - mid + 1];
    for (int i = left; i < mid; i++) {
        B[i - left] = A[i];
    }
    B[mid - left] = 2e9;
    for (int i = mid; i < right; i++) {
        C[i - mid] = A[i];
    }
    C[right - mid] = 2e9;
    
    int l_idx = 0, r_idx = 0;
    
    for (int i = left; i < right; i++) {
        if (B[l_idx] < C[r_idx]) {
            A[i] = B[l_idx];
            l_idx++;
        } else {
            A[i] = C[r_idx];
            r_idx++;
            cnt += mid - left - l_idx;
        }
    }
    return cnt;
}


long mergeSort(int *A, int left, int right, long cnt) {
    int mid = (left + right) / 2;
    if (left + 1 < right) {
        cnt = mergeSort(A, left, mid, cnt);
        cnt = mergeSort(A, mid, right, cnt);
        cnt = merge(A, left, right, mid, cnt);
    }
    return cnt;
}



int main() {
    int n;
    std::cin >> n;

    int A[n]; //, B[n];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    // std::memcpy(B, A, sizeof(int) * n);

    // int b_cnt = bubbleSort(B, n);
    long cnt = mergeSort(A, 0, n, 0);

    // std::cout << "bubble num = " << b_cnt << std::endl;
    // std::cout << "merge num = " << cnt << std::endl;
    std::cout << cnt << std::endl;
}
