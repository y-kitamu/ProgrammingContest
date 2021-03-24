#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    std::map<std::string, int> map;
    int max = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
        if (map.find(S[i]) == map.end()) {
            map[S[i]] = 0;
        }
        map[S[i]]++;
        max = std::max(map[S[i]], max);
    }
    std::sort(S.begin(), S.end());

    for (int i = 0; i < N; i++) {
        if (i + max - 1 < N && S[i] == S[i + max - 1]) {
            std::cout << S[i] << std::endl;
        }
    }
}
