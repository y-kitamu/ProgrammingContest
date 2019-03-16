#include <iostream>
#include <vector>

const int MAX_VAL = 2 * 10e5;
std::vector<std::vector<int>> indices(MAX_VAL, std::vector<int>());
int C[MAX_VAL] = {};
std::vector<int> count(MAX_VAL, -1);
std::vector<int> rev(MAX_VAL, -1);
int length = 1;

int reversi(int r_idx) {
    int cnt = 1;
    if (rev[r_idx] != -1) {
        return rev[r_idx];
    }
    for (int i = r_idx; i < length; i++) {
        // std::cout << i << std::endl;
        if (count[i] != -1) {
            cnt += count[i];
            continue;
        }
        
        int val = C[i];
        int num = indices[val].size();
        int j = 0;
        for (;j < num; j++) {
            if (indices[val][j] == i) break;
        }

        // std::cout << i << " , " << j << std::endl;

        if (num - j == 1) {
            count[i] = 0;
            continue;
        }
        
        j++;
        int tmp = 0;
        for (; j < num; j++) {
            tmp += reversi(indices[val][j] + 1);
        }
        count[i] = tmp;
        cnt += tmp;
    }
    rev[r_idx] = cnt;
    return cnt;
}

int main() {
    int N;
    std::cin >> N;

    std::cin >> C[0];
    indices[C[0]].push_back(0);
    
    for (int i = 1; i < N; i++) {
        int val;
        std::cin >> val;
        if (val != C[length - 1]) {
            C[length] = val;
            indices[val].push_back(length);
            length++;
        }
    }

    int cnt = reversi(0);

    std::cout << cnt << std::endl;
}
