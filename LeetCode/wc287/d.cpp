/*
 * d.cpp
 *
 * Create Date : 2022-04-03 11:47:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Encrypter {
  public:
    std::vector<char> keys;
    std::vector<std::string> values;
    std::map<std::string, int> cnts;

    Encrypter(std::vector<char>& keys, std::vector<std::string>& values,
              std::vector<std::string>& dictionary)
        : keys(keys), values(values) {
        for (auto& d : dictionary) {
            cnts[encrypt(d)]++;
        }
    }

    std::string encrypt(std::string word1) {
        std::string ans = "";
        for (auto& c : word1) {
            for (int i = 0; i < keys.size(); i++) {
                if (keys[i] == c) {
                    ans += values[i];
                }
            }
        }
        return ans;
    }

    int decrypt(std::string word2) { return cnts[word2]; }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */


int main() {}
