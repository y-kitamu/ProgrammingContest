#include <bits/stdc++.h>


bool test(const std::vector<int>& vec, const std::vector<int>& order, int cnt) {
    bool flag = true;
    for (int i = 0; i < (int)vec.size(); i++) {
        flag &= vec[i] == i;
    }
    for (int i = 0; i < cnt; i++) {
        flag &= order[i] % 2 != i % 2;
    }

    return flag;
}

void last3(int& v0, int& v1, int& v2, std::vector<int>& od, int& cnt, int N) {
    while (v0 > v1 || v1 > v2) {
        if (cnt % 2 != N % 2) {
            std::swap(v0, v1);
            od[cnt] = N - 2;
            cnt++;
        } else {
            std::swap(v1, v2);
            od[cnt] = N - 1;
            cnt++;
        }
    }
}

void last4(int& v0, int& v1, int& v2, int& v3, std::vector<int>& od, int& cnt, int N) {
    if (v0 == N - 4) {
        last3(v1, v2, v3, od, cnt, N);
    } else if (cnt % 2 != N % 2) {
        std::swap(v1, v2);
        od[cnt] = N - 2;
        cnt++;
        last4(v0, v1, v2, v3, od, cnt, N);
    } else if (v1 == N - 4 || v2 == N - 4) {
        std::swap(v0, v1);
        od[cnt] = N - 3;
        cnt++;
        last4(v0, v1, v2, v3, od, cnt, N);
    } else {
        std::swap(v2, v3);
        od[cnt] = N - 1;
        cnt++;
        last4(v0, v1, v2, v3, od, cnt, N);
    }
}

void print_order(const int& cnt, const std::vector<int>& order, const std::vector<int>& vec) {
    std::cout << cnt << std::endl;
    for (int j = 0; j < cnt; j++) {
        std::cout << order[j];
        if (j < cnt - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void print_vec(const std::vector<int>& vec) {
    for (auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void _print_order(const int& cnt, const std::vector<int>& order, const std::vector<int>& vec) {
    std::cout << "Ans" << std::endl;
    std::cout << cnt << std::endl;
    print_vec(vec);
    print_vec(order);
    if (!test(vec, order, cnt)) {
        std::cout << "Fail" << std::endl;
        std::exit(0);
    }
}


int main() {
    int T;
    std::cin >> T;

    // std::random_device seed_gen;
    // std::mt19937 engine(seed_gen());
    // std::uniform_int_distribution<> dist(2, 10);

    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        std::vector<int> p(N);
        for (int j = 0; j < N; j++) {
            std::cin >> p[j];
            p[j]--;
        }

        // std::cout << "== start trial i = " << i << " == " << std::endl;
        // int N = dist(engine);
        // std::vector<int> p(N);
        // std::iota(p.begin(), p.end(), 0);
        // std::shuffle(p.begin(), p.end(), engine);

        // std::cout << "N = " << N << std::endl;
        // print_vec(p);

        int cnt = 0;
        std::vector<int> order(N * N);

        if (N == 2) {
            if (p[0] == 0) {
                std::cout << 0 << std::endl;
                std::cout << std::endl;
            } else {
                std::cout << 1 << std::endl;
                std::cout << 1 << std::endl;
            }
            continue;
        } else if (N == 3) {
            last3(p[0], p[1], p[2], order, cnt, N);
            print_order(cnt, order, p);
            continue;
        }

        for (int j = 0; j < N - 4; j++) {
            int idx_j = j;
            for (; idx_j < N; idx_j++) {
                if (p[idx_j] == j) {
                    break;
                }
            }
            if (idx_j == j) {
                continue;
            }

            if (cnt % 2 == idx_j % 2) {
                for (int k = N - 2 - (cnt + N) % 2; k >= j; k -= 2) {
                    // std::cout << k << std::endl;
                    if (idx_j != k) {
                        std::swap(p[k], p[k + 1]);
                        order[cnt] = k + 1;
                        cnt++;
                        break;
                    }
                }
            }

            for (int k = idx_j - 1; k >= j; k--) {
                std::swap(p[k], p[k + 1]);
                order[cnt] = k + 1;
                cnt++;
            }
            // print_vec(p);
        }
        last4(p[N - 4], p[N - 3], p[N - 2], p[N - 1], order, cnt, N);
        print_order(cnt, order, p);
    }
}
