#include <iostream>
#include <vector>

static constexpr int MAX = 998244353;
int N, M, K;
std::vector<std::vector<long long int>> counts;

long long int search(int block, int ctr) {
    if (ctr < 0) {
        return 0;
    }
    if (block == 0) {
        if (ctr > 0) {
            return M;
        } else {
            return M - 1;
        }
    }

    if (counts[block][ctr] != -1) {
        return counts[block][ctr];
    }

    counts[block][ctr] = (search(block - 1, ctr - 1) + (M - 1) * search(block - 1, ctr)) % MAX;
    return counts[block][ctr];
}


int main() {
    std::cin >> N >> M >> K;
    counts = std::vector<std::vector<long long int>>(N, std::vector<long long int>(K + 1, -1));

    long long int count = (M * search(N - 2, K)) % MAX;
    std::cout << count << std::endl;
}
