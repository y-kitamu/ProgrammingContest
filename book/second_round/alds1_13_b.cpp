#include <bits/stdc++.h>

long long int N = 9;
long long int finish_key;
std::map<int, int> keys;

long long int calc_key(const std::vector<long long int> & puzzle) {
    long long int scale = 1;
    long long int key = 0;
    for (int i = 0; i < N; i++) {
        key += scale * puzzle[i];
        scale *= N;
    }
    return key;
}


std::vector<long long int> move_up(std::vector<long long int> puzzle, int white_idx) {
    if (white_idx + 3 < N) {
        std::swap(puzzle[white_idx], puzzle[white_idx + 3]);
    }
    return puzzle;
}

std::vector<long long int> move_down(std::vector<long long int> puzzle, int white_idx) {
    if (0 <= white_idx - 3) {
        std::swap(puzzle[white_idx], puzzle[white_idx - 3]);
    }
    return puzzle;
}

std::vector<long long int> move_left(std::vector<long long int> puzzle, int white_idx) {
    if (white_idx % 3 != 2) {
        std::swap(puzzle[white_idx], puzzle[white_idx + 1]);
    }
    return puzzle;
}

std::vector<long long int> move_right(std::vector<long long int> puzzle, int white_idx) {
    if (white_idx % 3 != 0) {
        std::swap(puzzle[white_idx], puzzle[white_idx - 1]);
    }
    return puzzle;
}

void search(int cnt, std::vector<long long int> puzzle) {
    std::cout << cnt << std::endl;
    if (keys.find(finish_key) != keys.end() && cnt >= keys[finish_key]) {
        return;
    }
    long long int key = calc_key(puzzle);
    if (key == finish_key) {
        if (keys.find(key) == keys.end() || cnt < keys[key]){
            keys[key] = cnt;
        }
        return;
    }
    if (keys.find(key) != keys.end()) {
        if (cnt < keys[key]) {
            keys[key] = cnt;
        } else {
            return;
        }
    } else {
        keys[key] = cnt;
    }
    auto iter = std::find(puzzle.begin(), puzzle.end(), 0);
    int white_idx = std::distance(puzzle.begin(), iter);
    search(cnt + 1, move_up(puzzle, white_idx));
    search(cnt + 1, move_down(puzzle, white_idx));
    search(cnt + 1, move_left(puzzle, white_idx));
    search(cnt + 1, move_right(puzzle, white_idx));
}


int main() {
    std::vector<long long int> puzzle(N);
    for (int i = 0; i < N; i++) {
        std::cin >> puzzle[i];
    }
    finish_key = calc_key({1, 2, 3, 4, 5, 6, 7, 8, 0});
    // search(0, puzzle);

    long long int key = calc_key(puzzle);
    int cnt = 0;
    std::queue<std::pair<int, std::vector<long long int>>> queues;
    while (key != finish_key) {
        keys[key] = cnt;

        auto iter = std::find(puzzle.begin(), puzzle.end(), 0);
        int white_idx = std::distance(puzzle.begin(), iter);
        {
            auto next = move_up(puzzle, white_idx);
            if (keys.find(calc_key(next)) == keys.end()) {
                queues.push(std::pair<int, std::vector<long long int>>(cnt + 1, next));
            }
        }
        {
            auto next = move_down(puzzle, white_idx);
            if (keys.find(calc_key(next)) == keys.end()) {
                queues.push(std::pair<int, std::vector<long long int>>(cnt + 1, next));
            }
        }
        {
            auto next = move_left(puzzle, white_idx);
            if (keys.find(calc_key(next)) == keys.end()) {
                queues.push(std::pair<int, std::vector<long long int>>(cnt + 1, next));
            }
        }
        {
            auto next = move_right(puzzle, white_idx);
            if (keys.find(calc_key(next)) == keys.end()) {
                queues.push(std::pair<int, std::vector<long long int>>(cnt + 1, next));
            }
        }

        auto que = queues.front();
        queues.pop();
        cnt = que.first;
        puzzle = que.second;
        key = calc_key(puzzle);
    }
    std::cout << cnt << std::endl;
}
