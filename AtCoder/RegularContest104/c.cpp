#include <bits/stdc++.h>


bool check_consistence(std::vector<int> floors) {
    bool reverse = false;
    int cnt = 0;
    for (int i = 0; i < floors.size(); i++) {
        if (!reverse && floors[i] == -1) {
            reverse = true;
            cnt--;
        } else if (!reverse && floors[i] == 1) {
            cnt++;
        } else if (reverse && floors[i] == 1) {
            if (cnt != 0) {
                return false;
            }
            reverse = false;
            cnt++;
        } else {
            cnt--;
        }

        if (cnt < 0) {
            return false;
        }
    }
    return cnt == 0;
}


bool step(int idx, int val, std::vector<int> floors, int on_res, int off_res) {
    floors[idx] = val;
    if (idx == floors.size() - 1) {
        return check_consistence(floors);
    }
    idx++;
    if (floors[idx] == 1) {
        if (on_res == 0) {
            return false;
        }
        return step(idx, 1, floors, on_res - 1, off_res);
    }
    if (floors[idx] == -1) {
        if (off_res == 0) {
            return false;
        }
        return step(idx, -1, floors, on_res, off_res - 1);
    }
    bool flag = false;
    if (on_res > 0) {
        flag |= step(idx, 1, floors, on_res - 1, off_res);
        if (flag) {
            return true;
        }
    }
    if (off_res > 0) {
        flag |= step(idx, -1, floors, on_res, off_res - 1);
        if  (flag) {
            return true;
        }
    }
    return flag;
};

int main() {
    int N;
    std::cin >> N;

    std::vector<int> floors(2 * N, 0);
    int on_res = N, off_res = N;
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a != -1)  {
            floors[a] = 1;
            on_res--;
        }
        if (b != -1) {
            floors[b] = -1;
            off_res--;
        }
    }

    if (floors[0] != -1 && step(0, 1, floors, on_res, off_res)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
