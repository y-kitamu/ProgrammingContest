#include <bits/stdc++.h>


using ll = long long int;

class Solution {
  public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        auto comp = [](auto& lhs, auto& rhs) { return std::get<2>(lhs) < std::get<2>(rhs); };

        std::priority_queue<std::tuple<ll, ll, double>, std::vector<std::tuple<ll, ll, double>>,
                            decltype(comp)>
            que{comp};
        double sum = 0;
        for (auto& clas : classes) {
            if (clas[0] == clas[1]) {
                sum += 1.0;
            } else {
                ll num = (ll)(clas[0] + 1) * clas[1] - ((ll)clas[0] * (clas[1] + 1));
                ll den = ((ll)clas[1] * (clas[1] + 1));
                que.push(std::make_tuple(clas[0], clas[1], (double)num / den));
            }
        }

        if (que.empty()) {
            return 1.0;
        }

        for (int i = 0; i < extraStudents; i++) {
            auto tup = que.top();
            que.pop();
            ll num = std::get<0>(tup) + 1;
            ll den = std::get<1>(tup) + 1;
            ll dnum = (ll)(num + 1) * den - ((ll)num * (den + 1));
            ll dden = (ll)(den * (den + 1));
            que.push(std::make_tuple(num, den, (double)dnum / dden));
        }

        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            // std::cout << top[0] << " " << top[1] << std::endl;
            sum += (double)std::get<0>(top) / std::get<1>(top);
        }
        return sum /= classes.size();
    }
};


int main() {}
