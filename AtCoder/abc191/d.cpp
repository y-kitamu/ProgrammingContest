#include <bits/stdc++.h>


long long int convert_to_int(std::string val) {
    int idx = 0;
    for (int i = 0; i < val.size(); i++) {
        if (val[i] == '.') {
            idx = i;
            break;
        }
    }
    if (idx == 0) {
        return std::stoi(val) * 10000;
    }
    long long int sub = std::stoi(val.substr(idx + 1));
    for (int i = val.size() - idx - 1; i < 4; i++) {
        sub *= 10;
    }
    return std::stoi(val.substr(0, idx)) * 10000 + sub;
}


int main() {
    std::string sX, sY, sR;
    std::cin >> sX >> sY >> sR;

    long long int X = convert_to_int(sX), Y = convert_to_int(sY), R = convert_to_int(sR);
    long long int min = ((X - R) / 10000 - 1) * 10000, max = ((X + R) / 10000 + 1) * 10000;

    auto judge_outside = [&X, &Y, &R](long long int x, long long int y) {
        return (x - X) * (x - X) + (y - Y) * (y - Y) > R * R;
    };

    long long int cnt = 0;
    for (long long int i = min; i <= max; i += 10000) {
        if (judge_outside(i, Y)) {
            continue;
        }
        long long int dy = (long long int)std::sqrt(R * R - (i - X) * (i - X));
        long long int min_y = ((Y - dy) / 10000 + 1) * 10000, max_y = ((Y + dy) / 10000 - 1) * 10000;
        if (min_y > max_y) {
            std::swap(min_y, max_y);
        }
        while (!judge_outside(i, min_y)) {
            min_y -= 10000;
        }
        while (!judge_outside(i, max_y)) {
            max_y += 10000;
        }
        min_y /= 10000;
        max_y /= 10000;
        cnt += (long long)max_y - min_y - 1;
    }

    std::cout << cnt << std::endl;
}
