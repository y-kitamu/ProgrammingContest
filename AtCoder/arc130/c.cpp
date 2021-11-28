/*
 * c.cpp
 *
 * Create Date : 2021-11-28 21:22:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int calc(int ia, int ib, int na, int nb, std::vector<int> cnta, std::vector<int> cntb) {
    if (cnta[ia] == 0 || cntb[ib] == 0) {
        return 1e9;
    }
    int has_zero = 0;
    cnta[ia]--;
    cntb[ib]--;
    for (int i = 0; i < 8; i++) {
        int min = std::min(cnta[i], cntb[7 - i]);
        cnta[i] -= min;
        cntb[7 - i] -= min;
        if (min > 0) {
            has_zero = 1;
            std::cout << "(" << i << ", " << 7 - i << "), ";
        }
    }
    std::cout << std::endl;
    if (na > nb) {
        if (cnta[8] > 0) {
            int min = std::min(cnta[8], na - nb);
            cnta[8] -= min;
        }
    }
    int ca = 0;
    int cb = 0;
    int sum = (ia + ib + 2) % 10 + has_zero;
    if (has_zero == 0 && (ia + ib + 2) > 10) {
        sum++;
    }
    int offset = 0;
    while (ca < 9 && cb < 9) {
        while (ca < 9 && cnta[ca] == 0) {
            ca++;
        }
        while (cb < 9 && cntb[cb] == 0) {
            cb++;
        }
        if (ca == 9 || cb == 9) {
            break;
        }
        std::cout << "(" << ca + 1 << ", " << cb + 1 << ", " << sum << "), ";
        int res = offset + ca + cb + 2;
        offset = res / 10;
        sum += res % 10;
        cnta[ca]--;
        cntb[cb]--;
    }
    std::cout << std::endl;
    sum += offset;

    while (ca != 9) {
        sum += cnta[ca] * (ca + 1);
        ca++;
    }

    return sum;
}


int main() {
    std::string a, b;
    std::cin >> a >> b;
    bool swaped = false;
    if (a.length() < b.length()) {
        swaped = true;
        std::swap(a, b);
    }

    std::vector<int> cnta(9, 0), cntb(9, 0);
    for (auto& c : a) {
        cnta[c - '1']++;
    }
    for (auto& c : b) {
        cntb[c - '1']++;
    }

    int na = a.length();
    int nb = b.length();
    int min = 1e9;
    int mina = -1, minb = -1;
    for (int ia = 0; ia < 9; ia++) {
        for (int ib = 0; ib < 9; ib++) {
            if (ia + ib < 8) {
                continue;
            }
            int val = calc(ia, ib, a.length(), b.length(), cnta, cntb);
            if (val < min) {
                min = val;
                mina = ia;
                minb = ib;
            }
            std::cout << ia << ", " << ib << ", " << val << std::endl;
        }
    }

    std::string ansa = "", ansb = "";
    ansa += (char)('1' + mina);
    ansb += (char)('1' + minb);
    cnta[mina]--;
    cntb[minb]--;
    for (int i = 0; i < 8; i++) {
        int min = std::min(cnta[i], cntb[7 - i]);
        cnta[i] -= min;
        cntb[7 - i] -= min;
        ansa = std::string(min, '1' + i) + ansa;
        ansb = std::string(min, '1' + 7 - i) + ansb;
        std::cout << cnta[i] << " " << cntb[7 - i] << std::endl;
    }
    int res = na - nb;
    if (cnta[8] > 0) {
        int min = std::min(cnta[8], na - nb);
        std::cout << min << ", " << ansa << std::endl;
        ansa = std::string(min, '9') + ansa;
        cnta[8] -= min;
        res -= min;
    }
    for (int i = 0; i < 9; i++) {
        int min = std::min(cnta[i], res);
        cnta[i] -= min;
        res -= min;
        if (min > 0) {
            ansa += std::string(min, '1' + i);
        }
        if (res == 0) {
            break;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (cnta[i] > 0) {
            std::cout << "i = " << i << std::endl;
            ansa = std::string(cnta[i], '1' + i) + ansa;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (cntb[i] > 0) {
            ansb += std::string(cntb[i], '1' + i);
        }
    }

    if (swaped) {
        std::swap(ansa, ansb);
    }

    std::cout << ansa << std::endl;
    std::cout << ansb << std::endl;
}
