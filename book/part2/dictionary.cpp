#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

class Dictionary {
public:
    Dictionary() {
        value = new bool[(int)std::pow(4, 13)];
        std::memset(value, 0, sizeof(bool) * (int)std::pow(4, 13));
    }

    int hash(std::string key) {
        int digit = 1, idx = 0;
        for (auto && c : key) {
            if (c == 'A') {
                idx += digit * 1;
            } else if (c == 'C') {
                idx += digit * 2;
            } else if (c == 'G') {
                idx += digit * 3;
            } else if (c == 'T') {
                idx += digit * 4;
            }
            digit *= 4;
        }
        return idx;
    }
    
    void insert(std::string key) {
        value[hash(key)] = true;
    }

    void find(std::string key) {
        if (value[hash(key)]) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    bool *value;
};


int main() {
    int queue;
    std::cin >> queue;

    Dictionary dict = Dictionary();
    
    for (int i = 0; i < queue; i++) {
        std::string order, key;
        std::cin >> order >> key;
        if (order == "insert") {
            dict.insert(key);
        } else if (order == "find") {
            dict.find(key);
        }
    }
}
