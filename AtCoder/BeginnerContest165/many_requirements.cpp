#include <iostream>
#include <vector>
#include <functional>


struct Pair {
    int a, b, c, d;
};

static int N, M, Q;
static int max;
static std::vector<Pair> pairs;

void count(std::vector<int> vals) {
    int sum = 0;
    for (auto && pair : pairs) {
        if (vals[pair.b - 1] - vals[pair.a - 1] == pair.c) {
            sum += pair.d;
        }
    }
    if (max < sum) {
        max = sum;
    }
}

void combination() {
    std::vector<int> indices(N);
    int start_index = 1;
    int size = 0;

    while (size >= 0) {
        for (int i = start_index; i <= M;) {
            indices[size++] = i;
            if (size == N) {
                count(indices);
                break;
            }
        }
        size--;
        start_index = indices[size] + 1;
    }
}


int main() {
    std::cin >> N >> M >> Q;

    pairs = std::vector<Pair>(Q);
    max = 0;

    for (int i = 0; i < Q; i++) {
        std::cin >> pairs[i].a >> pairs[i].b >> pairs[i].c >> pairs[i].d;
    }

    combination();

    std::cout << max << std::endl;
}
