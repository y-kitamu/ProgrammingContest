/*
 * c.cpp
 *
 * Create Date : 2021-11-21 11:37:17
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class RangeFreqQuery {
  public:
    RangeFreqQuery(std::vector<int>& arr) : seg(arr.size() * 4) {
        int val = 1;
        while (val < arr.size()) {
            val *= 2;
        }
        maximum = val;
        for (int i = 0; i < arr.size(); i++) {
            insert(i, 0, 0, maximum, arr[i]);
        }
    }

    void insert(int idx, int cur, int min, int max, int value) {
        std::cout << idx << " , " << cur << " , " << min << " , " << max << ", " << value << std::endl;
        seg[cur][value]++;
        if (max - min > 1) {
            int mid = (max + min) / 2;
            if (idx < mid) {
                insert(idx, cur * 2 + 1, min, mid, value);
            } else {
                insert(idx, cur * 2 + 2, mid, max, value);
            }
        }
    }

    int query(int left, int right, int value) { return find(left, right + 1, value, 0, maximum, 0); }

    int find(int left, int right, int value, int min, int max, int idx) {
        std::cout << "find " << left << ", " << right << " , " << value << ", " << min << ", " << max
                  << ", " << idx << std::endl;
        if ((max <= left) || (right <= min)) {
            return 0;
        }
        if (left <= min && max <= right) {
            return seg[idx][value];
        }
        int sum = 0;
        int mid = (min + max) / 2;
        sum += find(left, right, value, min, mid, idx * 2 + 1);
        sum += find(left, right, value, mid, max, idx * 2 + 2);
        return sum;
    }

    int maximum;
    std::vector<std::map<int, int>> seg;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main() {}
