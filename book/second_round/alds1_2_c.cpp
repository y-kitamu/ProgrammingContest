#include <iostream>
#include <cstring>
#include <string>

// #include <glog/logging.h>

void bubbleSort(std::string * A, int * idx, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            if (idx[j] < idx[j - 1]) {
                std::swap(A[j], A[j - 1]);
                std::swap(idx[j], idx[j - 1]);
            }
        }
    }
}

void selectionSort(std::string * A, int * idx, int N) {
    for (int i = 0; i < N; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (idx[min_idx] > idx[j]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(A[min_idx], A[i]);
            std::swap(idx[min_idx], idx[i]);
        }
    }
}

void printSort(std::string * A, int N) {
    for (int i = 0; i < N - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[N - 1] << std::endl;
}

bool isStable(std::string * A, std::string * sorted, int N) {
    bool is_stable = true;
    for (int i = 0; i < N - 1; i++) {
        if (sorted[i][1] == sorted[i + 1][1]) {
            for (int j = 0; j < N; j++) {
                if (A[j] == sorted[i]) {
                    is_stable = true;
                    break;
                } else if (A[j] == sorted[i + 1]) {
                    is_stable = false;
                    break;
                }
            }
            if (!is_stable) {
                std::cout << "Not stable" << std::endl;
                return is_stable;
            }
        }
    }
    std::cout << "Stable" << std::endl;
    return is_stable;
}

int main(int argc, char ** argv) {
// #ifdef NDEBUG
//     google::InitGoogleLogging(argv[0]);
//     google::InstallFailureSignalHandler();
// #endif
    
    int N;
    std::cin >> N;

    std::string A[N], A_bubble[N], A_select[N];
    int bubble[N], select[N];
    
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A_bubble[i] = A_select[i] = A[i];
        bubble[i] = select[i] = std::atoi(&A[i][1]);
    }

    bubbleSort(A_bubble, bubble, N);
    selectionSort(A_select, select, N);

    printSort(A_bubble, N);
    isStable(A, A_bubble, N);
    printSort(A_select, N);
    isStable(A, A_select, N);
}
