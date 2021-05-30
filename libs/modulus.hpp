/*
 * modulus.hpp
 *
 *
 * Create Date : 2020-04-26 19:27:18
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */

#ifndef MODULUS_HPP__
#define MODULUS_HPP__

namespace myalg {


long long modpow(long long a, long long n, long long mod) {
    long long int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


}

#endif // MODULUS_HPP__
