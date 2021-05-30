#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <class T, class Comp>
std::vector<int> index_sort(const std::vector<T>& vec, Comp comp = std::less(), const int offset = 0) {
    std::vector<int> indices(vec.size());
    std::iota(vec.begin(), vec.end(), offset);

    std::sort(indices.begin(), indices.end(), comp);
    return indices;
}


template <class T>
void print_vec(const std::vector<T>& vec) {
    for (auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

#endif
