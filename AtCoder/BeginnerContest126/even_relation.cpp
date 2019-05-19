#include <iostream>
#include <vector>
#include <map>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::map<int, int>> node(N, std::map<int, int>());
    std::vector<int> color(N), mapped(N, -1);

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u = u - 1;
        v = v - 1;
        node[u][v] = w;
        node[v][u] = w;
    }

    color[0] = 0; mapped[0] = 0;

    std::vector<int> idx_list {0};
    for (auto i : node[0]) {
        mapped[i.first] = 0;
    }

    while (idx_list.size() > 0) {
        // std::cout << idx_list[0] << std::endl;
        for (auto i : idx_list) {
            std::cout << " " << i;
        }
        std::cout << std::endl;
        for (auto && i : node[idx_list[0]]) {
            std::cout << mapped[i.first] << " , " << color[mapped[i.first]] << " , "
                      << i.first << ", " << i.second << std::endl;
            color[i.first] = (color[mapped[i.first]] + i.second % 2) % 2;
            mapped[i.first] = 1;
            for (auto j : node[i.first]) {
                if (mapped[j.first] == -1) {
                    idx_list.emplace_back(j.first);
                    mapped[j.first] = i.first;
                }
            }
        }
        idx_list.erase(idx_list.begin());
    }

    for (auto && i : color) {
        std::cout << i << std::endl;
    }
}
