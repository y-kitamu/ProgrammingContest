/*
 * alds1_9_c.cpp
 *
 * Create Date : 2020-03-29 10:26:53
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>

static int S[2000000];
static int idx = 0;

void insert() {
    int child = idx;
    int parent = child / 2;
    while (parent > 0) {
        if (S[child] > S[parent]) {
            std::swap(S[child], S[parent]);
        }
        child = parent;
        parent = parent / 2;
    }
}

void heapify(int parent) {
    int left = parent * 2;
    int right = left + 1;
    int largest = parent;
    if (left <= idx && S[largest] < S[left]) {
        largest = left;
    }
    if (right <= idx && S[largest] < S[right]) {
        largest = right;
    }
    if (largest != parent) {
        std::swap(S[parent], S[largest]);
        heapify(largest);
    }
}

void extractMax() {
    std::cout << S[1] << std::endl;
    std::swap(S[1], S[idx]);
    idx--;
    heapify(1);
}


int main() {
    std::string command;
    while (true) {
        std::cin >> command;
        if (command == "insert") {
            idx++;
            std::cin >> S[idx];
            insert();
        } else if (command == "extract") {
            extractMax();
        } else if (command == "end") {
            break;
        }
    }
}
