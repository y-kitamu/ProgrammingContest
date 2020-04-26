/*
 * two_currencies.cpp
 *
 * Create Date : 2020-04-26 22:37:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>


struct Line {
    Line(int next, int cost, int time): next(next), cost(cost), time(time) {}
    int next;
    int cost;
    int time;
};


struct City {
    int rate;
    int time;
};


struct Link {

};


int calc_time(int dst, std::vector<std::vector<Line>> &lines, std::vector<City>& cities) {

}


int main() {
    int N, M, S;
    std::cin >> N >> M >> S;

    std::vector<std::vector<Line>> lines(M);
    for (int i = 0; i < M; i++) {
        int u, v, a, b;
        std::cin >> u >> v >> a >> b;
        lines[u - 1].emplace_back(Line(v - 1, a, b));
        lines[v - 1].emplace_back(Line(u - 1, a, b));
    }

    std::vector<City> cities(N, City());
    for (int i = 0; i < N; i++) {
        std::cin >> cities[i].rate >> cities[i].time;
    }

    for (int i = 1; i < N; i++) {

    }
}
