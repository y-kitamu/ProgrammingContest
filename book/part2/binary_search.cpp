#include <iostream>


int binarySearch(int arr[], int N, int key) {
    if (N == 1) {
        return arr[0] == key;
    }
    if (arr[N / 2 - 1] < key) {
        return binarySearch(arr + N / 2, N - N / 2, key);
    } else {
        return binarySearch(arr, N / 2, key);
    }
}

int binarySearch2(int arr[], int N, int key) {
    int left = 0, right = N, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        } else if (key < arr[mid]) {
            right = mid - 1;
        } else {
            return true;
        }
    }
    return arr[left] == key;
}


int main() {
    int N, Q;
    std::cin >> N;

    int S[N];
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    std::cin >> Q;
    int cnt = 0;
    for (int i = 0; i < Q; i++) {
        int key;
        std::cin >> key;
        cnt += binarySearch2(S, N, key);
    }

    std::cout << cnt << std::endl;
}
