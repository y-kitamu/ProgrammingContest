#include <iostream>
#include <vector>


int main() {
    int N, M, C;
    std::cin >> N >> M >> C;

    int B[M];
    
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int sum = 0, val;
        for (int j = 0; j < M; j++) {
            std::cin >> val;
            sum += B[j] * val;
        }
        if (sum + C > 0) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;

}
