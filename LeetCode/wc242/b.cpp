#include <bits/stdc++.h>


class Solution {
  public:
    int minSpeedOnTime(std::vector<int>& dist, double hour) {
        int ihour = 0;
        bool flag = false;
        int scale = 1;
        for (auto& c : std::to_string(hour)) {
            if (c == '.') {
                flag = true;
                continue;
            }
            ihour *= 10;
            ihour += c - '0';
            if (flag) {
                scale *= 10;
            }
            if (scale == 100) {
                break;
            }
        }

        int min = 1, max = 2e7;
        if (!calc(dist, max, ihour, scale)) {
            return -1;
        }

        while (min != max) {
            int mid = (max + min) / 2;
            if (calc(dist, mid, ihour, scale)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }

    bool calc(std::vector<int>& dist, long long int speed, long long int ihour, long long int scale) {
        long long int n = dist.size();
        long long int time = 0;
        for (int i = 0; i < n - 1; i++) {
            time += (dist[i] / speed) * scale;
            if (dist[i] % speed != 0) {
                time += 100;
            }
        }
        return (ihour - time) * speed >= (long long int)dist[n - 1] * scale;
    }
};

int main() {}
