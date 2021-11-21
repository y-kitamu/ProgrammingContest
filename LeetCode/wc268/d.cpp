/*
 * d.cpp
 *
 * Create Date : 2021-11-21 12:08:01
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long kMirror(int k, int n) {
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += vals[k][i];
        }
        return sum;
    }


    std::vector<std::vector<long long>> vals{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1,       3,       5,        7,         9,         33,       99,      313,
         585,     717,     7447,     9009,      15351,     32223,    39993,   53235,
         53835,   73737,   585585,   1758571,   1934391,   1979791,  3129213, 5071705,
         5259525, 5841485, 13500531, 719848917, 910373019, 939474939},
        {1,       2,       4,       8,       121,     151,     212,     242,     484,      656,
         757,     29092,   48884,   74647,   75457,   76267,   92929,   93739,   848848,   1521251,
         2985892, 4022204, 4219124, 4251524, 4287824, 5737375, 7875787, 7949497, 27711772, 83155138},
        {1,       2,       3,        5,         55,        373,        393,     666,
         787,     939,     7997,     53235,     55255,     55655,      57675,   506605,
         1801081, 2215122, 3826283,  3866683,   5051505,   5226225,    5259525, 5297925,
         5614165, 5679765, 53822835, 623010326, 954656459, 51717171715},
        {1,          2,          3,          4,          6,           88,         252,       282,
         626,        676,        1221,       15751,      18881,       10088001,   10400401,  27711772,
         30322303,   47633674,   65977956,   808656808,  831333138,   831868138,  836131638, 836181638,
         2512882152, 2596886952, 2893553982, 6761551676, 12114741121, 12185058121},
        {1,      2,      3,      4,       5,       7,       55,      111,     141,     191,
         343,    434,    777,    868,     1441,    7667,    7777,    22022,   39893,   74647,
         168861, 808808, 909909, 1867681, 3097903, 4232324, 4265624, 4298924, 4516154, 4565654},
        {1,         2,           3,           4,           5,           6,          8,         121,
         171,       242,         292,         16561,       65656,       2137312,    4602064,   6597956,
         6958596,   9470749,     61255216,    230474032,   466828664,   485494584,  638828836, 657494756,
         858474858, 25699499652, 40130703104, 45862226854, 61454945416, 64454545446},
        {1,     2,     3,      4,      5,      6,       7,       9,       121,     292,
         333,   373,   414,    585,    3663,   8778,    13131,   13331,   26462,   26662,
         30103, 30303, 207702, 628826, 660066, 1496941, 1935391, 1970791, 4198914, 55366355},
        {1,      2,       3,       4,       5,       6,       7,       8,       191,     282,
         373,    464,     555,     646,     656,     6886,    25752,   27472,   42324,   50605,
         626626, 1540451, 1713171, 1721271, 1828281, 1877781, 1885881, 2401042, 2434342, 2442442},
    };
};


long long reverse(long long val) {
    std::vector<int> ints;
    while (val > 0) {
        ints.emplace_back(val % 10);
        val /= 10;
    }
    long long res = 0;
    for (auto& i : ints) {
        res = res * 10 + i;
    }
    return res;
}


bool judge(long long val, int k) {
    std::vector<int> ints;
    while (val > 0) {
        ints.emplace_back(val % k);
        val /= k;
    }
    bool flag = true;
    int n = ints.size();
    for (int i = 0; i < n / 2; i++) {
        flag &= ints[i] == ints[n - i - 1];
    }
    return flag;
}


int main() {
    std::vector<std::vector<long long>> vals(10, std::vector<long long>(30));
    for (int k = 2; k <= 9; k++) {
        int idx = 0;

        for (int i = 1; i < 10; i++) {
            if (judge(i, k)) {
                vals[k][idx] = i;
                idx++;
            }
        }

        long long scale = 1;
        while (idx < 30) {
            for (int i = scale; i < scale * 10; i++) {
                long long val = i * (scale * 10) + reverse(i);
                if (judge(val, k)) {
                    vals[k][idx] = val;
                    idx++;
                }
                if (idx >= 30) {
                    break;
                }
            }

            for (int i = scale; i < scale * 10; i++) {
                for (int j = 0; j < 10; j++) {
                    long long val = (i * 10 + j) * (scale * 10) + reverse(i);
                    if (judge(val, k)) {
                        vals[k][idx] = val;
                        idx++;
                    }
                }
                if (idx >= 30) {
                    break;
                }
            }
            scale *= 10;
        }
    }


    for (auto& vec : vals) {
        std::cout << "{";
        for (auto& val : vec) {
            std::cout << val << ", ";
        }
        std::cout << "}" << std::endl;
    }
}
