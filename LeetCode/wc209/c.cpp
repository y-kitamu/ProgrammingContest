#include <bits/stdc++.h>


class Solution {
public:
    int visiblePoints(std::vector<std::vector<int>>& points, int angle, std::vector<int>& location) {
        std::vector<double> angles;
        int cnt = 0;
        for (auto pt : points) {
            int dx = pt[0] - location[0];
            int dy = pt[1] - location[1];
            if (dx == 0 && dy == 0) {
                cnt++;
                continue;
            }
            double dangle = acos(double(dx) / std::sqrt(dx * dx +  dy * dy)) * 180 / M_PI;
            if (dy < 0) {
                dangle += 180;
            }
            angles.emplace_back(dangle);
        }

        std::sort(angles.begin(), angles.end(), [] (auto &lhs, auto& rhs) { return lhs < rhs; });

        int max_count = 0;
        int max_idx = 0;
        for (int i = 0; i < angles.size(); i++) {
            double max_angle = angles[i] + angle;
            int j = max_idx;
            if (j < i) {
                max_angle -= 360;
            }
            while (angles[j] <= max_angle) {
                if (j == angles.size() - 1) {
                    max_angle -= 360;
                    j = 0;
                } else {
                    j++;
                }
            }
            if (j > i) {
                max_count = std::max(max_count, j - i);
            } else {
                max_count = std::max(max_count, (int)angles.size() + j - i);
            }
            max_idx = j;
        }
        return max_count + cnt;
    }
};


int main() {
    // std::vector<std::vector<int>> points {{0,1},{2,1}};
    std::vector<std::vector<int>> points {{1,1},{2,2},{3,3},{4,4},{1,2},{2,1}}; //{{1,1},{2,2},{1,2},{2,1}};
    int angle = 0;
    std::vector<int> location {1,1};
    std::cout << Solution().visiblePoints(points, angle, location) << std::endl;;
}
