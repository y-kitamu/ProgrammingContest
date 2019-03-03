#include <iostream>
#include <vector>
#include <utility>
#include <queue>


int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<bool>> is_movable(N, std::vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        is_movable[i][i] = true;
    }
    std::vector<std::pair<int, int>> bridges(M);

    for (int i = 0; i < M; i++) {
        int A, B;
        std::cin >> A >> B;
        bridges[i] = std::make_pair(A, B);
    }

    long inconvinience = N * (N - 1) / 2;
    std::vector<long> inconvs(M + 1);
    inconvs[M] = inconvinience;
    std::queue<std::pair<int, int>> queue;
    for (int i = M - 1; i >= 0; i--) {
        // std::cout << i << std::endl;

        if (!is_movable[bridges[i].first - 1][bridges[i].second - 1]) {
            queue.push(bridges[i]);
        }
        
        while (!queue.empty()) {
            auto bg = queue.front();
            queue.pop();
            
            // std::cout << bg.first << " , " << bg.second << std::endl;
            if (is_movable[bg.first - 1][bg.second - 1]) continue;
                
            is_movable[bg.first - 1][bg.second - 1] = true;
            is_movable[bg.second - 1][bg.first - 1] = true;
                
            for (int j = 1; j <= N; j++) {
                if (is_movable[bg.first - 1][j - 1] && !is_movable[j - 1][bg.second - 1]) {
                    queue.push(std::make_pair(bg.second, j));
                }
                if (is_movable[bg.second - 1][j - 1] && !is_movable[j - 1][bg.first - 1]) {
                    queue.push(std::make_pair(bg.first, j));
                }
            }
            inconvinience--;
        }
        inconvs[i] = inconvinience;
    }

    for (int i = 1; i <= M; i++) {
        std::cout << inconvs[i] << std::endl;
    }
}
