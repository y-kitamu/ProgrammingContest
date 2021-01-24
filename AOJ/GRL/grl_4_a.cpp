#include <bits/stdc++.h>


int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> edges(E, std::vector<int>(2));
    for (int i = 0; i < E; i++) {
        std::cin >> edges[i][0] >> edges[i][1];
    }

    std::vector<int> value(V, 0);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            value[edges[j][1]] = std::max(value[edges[j][0]] + 1, value[edges[j][1]]);
        }
    }

    bool flag = false;
    for (int j = 0; j < E; j++) {
        if (value[edges[j][0]] + 1 > value[edges[j][1]]) {
            flag = true;
            break;
        }
    }

    if (flag) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}
