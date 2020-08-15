#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> ls(N);
    for (int i = 0; i < N; i++) {
        std::cin >> ls[i];
    }

    std::sort(ls.begin(), ls.end());
    int count = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (ls[i] == ls[j]) {
                continue;
            }
            for (int k = j + 1; k < N; k++) {
                if (ls[j] == ls[k]) {
                    continue;
                }
                if (ls[i] + ls[j] <= ls[k]) {
                    break;
                }
                count++;
            }
        }
    }
    std::cout << count << std::endl;
}
