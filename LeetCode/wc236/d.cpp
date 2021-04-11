#include <bits/stdc++.h>

using ll = long long int;


class MKAverage {
  public:
    MKAverage(int m, int k) : cnt(0), sum(0), m(m), k(k) {
        que = std::queue<int>();
        container.clear();
    }

    void addElement(int num) {
        que.push(num);
        container.insert(num);
        if (que.size() >= m) {
            int idx = std::distance(container.begin(), container.lower_bound(num));
            if (k <= idx && idx < container.size() - k) {
                sum += num;
            }
        }
        if (que.size() > m) {
            int val = que.front();
            auto itr = container.find(val);
            int idx = std::distance(container.begin(), itr);
            if (k <= idx && idx < container.size() - k) {
                sum -= num;
            }
        }
    }

    int calculateMKAverage() {
        if (que.size() < m) {
            return -1;
        }
        return sum / (m - 2 * k);
    }

    int cnt = 0;
    ll sum = 0;
    int m, k;
    std::queue<int> que;
    std::multiset<int> container;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */


int main() {}
