#include <bits/stdc++.h>


class Solution {
public:
    int minimumTimeRequired(std::vector<int>& jobs, int k) {
        std::sort(jobs.begin(), jobs.end(), [](auto lhs, auto rhs) { return lhs > rhs; });
        int sum = 0;
        for (auto job : jobs) {
            sum += job;
        }
        return binarySearch(jobs, k, 0, sum);
    }

    int binarySearch(std::vector<int>& jobs, int k, int left, int right) {
        if (left == right) {
            return left;
        }
        int mid = (left + right) / 2;
        if (judge(mid, jobs, k)) {
            return binarySearch(jobs, k, left, mid);
        }
        return binarySearch(jobs, k, mid + 1, right);
    }

    bool judge(int time, std::vector<int>& jobs, int k) {
        std::vector<bool> used(jobs.size(), false);
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (int i = 0; i < jobs.size(); i++) {
                if (used[i]) {
                    continue;
                }
                if (sum + jobs[i] < time) {
                    sum += jobs[i];
                    used[i] = true;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < used.size(); i++) {
            flag &= used[i];
        }
        return flag;
    }
};


int main() {

}
