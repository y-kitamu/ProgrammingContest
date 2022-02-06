/*
 * c.cpp
 *
 * Create Date : 2022-02-06 11:42:42
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Bitset {
  public:
    int size;
    bool is_flip;
    std::set<int> ones;

    Bitset(int size) : size(size), is_flip(false), ones(std::set<int>()) {}

    void fix(int idx) {
        if (is_flip) {
            ones.erase(idx);
        } else {
            ones.insert(idx);
        }
    }

    void unfix(int idx) {
        if (is_flip) {
            ones.insert(idx);
        } else {
            ones.erase(idx);
        }
    }

    void flip() { is_flip = !is_flip; }

    bool all() {
        if (is_flip) {
            return ones.size() == 0;
        }
        return ones.size() == size;
    }

    bool one() {
        if (is_flip) {
            return ones.size() < size;
        }
        return ones.size() > 0;
    }

    int count() {
        if (is_flip) {
            return size - ones.size();
        }
        return ones.size();
    }

    std::string toString() {
        std::string res = "";
        for (int i = 0; i < size; i++) {
            if (ones.find(i) == ones.end()) {
                if (is_flip) {
                    res += "1";
                } else {
                    res += "0";
                }
            } else {
                if (is_flip) {
                    res += "0";
                } else {
                    res += "1";
                }
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */


int main() {}
