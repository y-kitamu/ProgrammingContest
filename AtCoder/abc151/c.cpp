#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> ac(N, 0), wa(N, 0);
    for (int i = 0; i < M; i++) {
        int val;
        std::string res;
        std::cin >> val >> res;
        val--;
        if (ac[val] == 1) {
            continue;
        }
        if (res == "WA") {
            wa[val]++;
        } else if (res == "AC") {
            ac[val] = 1;
        }
    }

    int acs = 0, was = 0;
    for (int i = 0; i < N; i++) {
        acs += ac[i];
        if (ac[i] == 1) {
            was += wa[i];
        }
    }
    std::cout << acs << " " << was << std::endl;
}
