#include <bits/stdc++.h>


bool calc(int k, std::string S, std::vector<int> A, std::vector<std::vector<int>>& vec) {
    vec = std::vector<std::vector<int>>(k, std::vector<int>(A.size()));

    for (int i = 0; i < k; i++) {
        vec[i][0] = A[0] / k;
    }
    for (int i = 0; i < A[0] % k; i++) {
        vec[i][0]++;
    }

    for (int i = 1; i < A.size(); i++) {
        int val = A[i] / k;
        for (int j = 0; j < k; j++) {
            vec[j][i] = val;
            A[i] -= val;
        }
        for (int j = 0; j < A[i]; j++) {
            vec[j % k][i]++;
        }

        for (int j = 0; j < k; j++) {
            if (S[i - 1] == '>' && vec[j][i - 1] <= vec[j][i]) {
                return false;
            }
            if (S[i - 1] == '<' && vec[j][i - 1] >= vec[j][i]) {
                return false;
            }
        }
    }
    return true;
}


int binarySearch(int min, int max, std::string& S, std::vector<int>& A) {
    if (min == max) {
        return min;
    }
    int mid = (min + max + 1) / 2;
    std::vector<std::vector<int>> ans;
    if (calc(mid, S, A, ans)) {
        return binarySearch(mid, max, S, A);
    }
    return binarySearch(min, mid - 1, S, A);
}


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;
    std::vector<int> A(N + 1);
    for (int i = 0; i <= N; i++) {
        std::cin >> A[i];
    }

    int k = binarySearch(0, 1e4, S, A);
    std::vector<std::vector<int>> ans;
    calc(k, S, A, ans);
    std::cout << k << std::endl;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < A.size(); j++) {
            std::cout << ans[i][j];
            if (j < A.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
