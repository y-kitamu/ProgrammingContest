#include <bits/stdc++.h>

struct City {
    long long int x, y;
    long long int p;
    long long int distance;
};


long long int calc_cost(const std::vector<City> &cities) {
    long long int cost = 0;
    for (auto city : cities) {
        cost += city.distance * city.p;
    }
    return cost;
}


long long int calc_cost_x(const std::vector<City> &cities, int idx) {
    long long int cost = 0;
    for (auto city : cities) {
        cost += std::min(city.distance, std::abs(city.x - idx)) * city.p;
    }
    return cost;
}

long long int calc_cost_y(const std::vector<City> &cities, int idx) {
    long long int cost = 0;
    for (auto city : cities) {
        cost += std::min(city.distance, std::abs(city.y - idx)) * city.p;
    }
    return cost;
}



int main() {
    int N;
    std::cin >> N;

    std::vector<City> cities(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cities[i].x >> cities[i].y >> cities[i].p;
        cities[i].distance = std::min(std::abs(cities[i].x), std::abs(cities[i].y));
    }
    std::cout <<  calc_cost(cities) << std::endl;

    std::sort(cities.begin(), cities.end(), [](auto &lhs, auto &rhs) {return lhs.p > rhs.p; });
    for (int i = 0; i < N; i++) {

    }

    std::vector<int> xs(N, 0), ys(N, 0);


}
