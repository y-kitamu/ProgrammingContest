/*
 * b.cpp
 *
 * Create Date : 2021-10-17 11:38:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Bank {
  public:
    Bank(std::vector<long long>& balance) : balance(balance), n(balance.size()) {}

    bool check_idx(int idx) { return 0 <= idx && idx < n; }

    bool transfer(int account1, int account2, long long money) {
        int a1 = account1 - 1, a2 = account2 - 1;
        if (!check_idx(a1)) {
            return false;
        }
        if (!check_idx(a2)) {
            return false;
        }
        if (money > balance[a1]) {
            return false;
        }
        balance[a1] -= money;
        balance[a2] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!check_idx(account - 1)) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        int a = account - 1;
        if (!check_idx(a)) {
            return false;
        }
        if (money > balance[a]) {
            return false;
        }
        balance[a] -= money;
        return true;
    }

    std::vector<long long> balance;
    int n;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */


int main() {}
