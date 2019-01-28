#include <iostream>
#include <sstream>
#include <cstring>

void showResult(std::string *arr, bool stable, int N) {
    for (int i = 0; i < N; i++) {
        std::cout << arr[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    if (stable) {
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }
}

bool checkStable(std::string *str_in, std::string *str_sort, int * arr, int N) {
    bool stable = true;
    for (int i = 0; i < N; i++) {
        if (arr[i] == arr[i + 1]) {
            for (int j = 0; j < N; j++) {
                if (str_sort[i] == str_in[j]) break;
                if (str_sort[i + 1] == str_in[j]) {
                    stable = false;
                    break;
                }
            }
        }
        if (!stable) break;
    }
    return stable;
}


void bubbleSort(int *A, std::string *input, int N) {
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = N - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                std::swap(A[j - 1], A[j]);
                std::swap(input[j - 1], input[j]);
                flag = false;
            }
        }
        if (flag) break;
    }
}

void selectionSort(int *A, std::string *input, int N) {
    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (A[min_idx] > A[j]) {
                min_idx = j;
            }
        }
        std::swap(A[min_idx], A[i]);
        std::swap(input[min_idx], input[i]);
    }
    
}

int main(int argc, char ** argv) {
    int N;
    std::cin >> N;

    std::string str_arr[N], str_arr1[N], str_arr2[N];
    int arr[N], arr1[N], arr2[N];
    for (int i = 0; i < N; i++) {
        std::cin >> str_arr[i];
        str_arr1[i] = str_arr[i];
        str_arr2[i] = str_arr[i];
        arr[i] = (int)(str_arr[i][1]);
    }

    std::memcpy(arr1, arr, sizeof(int) * N);
    std::memcpy(arr2, arr, sizeof(int) * N);

    bubbleSort(arr1, str_arr1, N);
    selectionSort(arr2, str_arr2, N);

    bool s1 = checkStable(str_arr, str_arr1, arr1, N);
    bool s2 = checkStable(str_arr, str_arr2, arr2, N);

    showResult(str_arr1, s1, N);
    showResult(str_arr2, s2, N);
}
