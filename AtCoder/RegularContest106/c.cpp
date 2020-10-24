#include <bits/stdc++.h>


int count(std::vector<std::vector<int>> vecs) {
    int max = vecs[0][0] - 1;
    int cnt = 0;
    for (int i = 0; i < vecs.size(); i++) {
        if (max < vecs[i][0]) {
            cnt++;
            max = vecs[i][1];
        }
    }
    return cnt;
}


int validation_check(std::vector<std::vector<int>> vecs) {
    std::sort(vecs.begin(), vecs.end(), [] (auto lhs, auto rhs) { return lhs[0] < rhs[0]; });
    int a = count(vecs);
    std::sort(vecs.begin(), vecs.end(), [] (auto lhs, auto rhs) { return lhs[1] < rhs[1]; });
    int b = count(vecs);
    return a - b;
}


std::vector<std::vector<int>> run(int N, int M) {

    std::vector<std::vector<int>> vecs(N, std::vector<int>(2, -1));
     if (M == 0) {
        for (int i = 0; i < N; i++) {
            vecs[i][0] = 2 * i + 1;
            vecs[i][1] = 2 * (i + 1);
        }
    } else if (std::abs(M) > N - 2) {
    } else if (M > 0) {
        vecs[0][0] = 1;
        vecs[0][1] =  2 * (M + 2);
        int i = 1;
        for (;i <= M + 1; i++) {
            vecs[i][0] = 2 * i;
            vecs[i][1] = 2 * i + 1;
        }
        for (; i < N; i++) {
            vecs[i][0] = 2 * i + 1;
            vecs[i][1] = 2 * (i + 1);
        }
    }

    // std::cout << vecs[0][0] << std::endl;
    // if (vecs[0][0] > -1) {
    //     int res = validation_check(vecs);
    //     std::cout << res << " " << M << std::endl;
    //     if (res != M) {
    //         std::cout << "N = " << N << ", M = " << M << std::endl;
    //         for (auto vec : vecs) {
    //             std::cout << vec[0] << " " << vec[1] << std::endl;
    //         }
    //         std::exit(0);
    //     }
    // }
    return vecs;
}


int main() {

    // std::mt19937 gen{std::random_device{}()};
    // std::uniform_int_distribution<> dist(1, 20);
    // for (int i = 0; i < 100; i++) {
    //     int N = dist(gen);
    //     int M = dist(gen) - 10;
    //     run(N, M);
    // }
    int N, M;
    std::cin >> N >> M;
    auto vecs = run(N, M);
    if (vecs[0][0] == -1) {
        std::cout << -1 << std::endl;
    } else {
        for (auto vec : vecs) {
            std::cout << vec[0] << " " << vec[1] << std::endl;
        }
    }
}
