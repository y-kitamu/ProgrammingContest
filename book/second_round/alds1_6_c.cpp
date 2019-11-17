/*
 * alds1_6_c.cpp
 *
 * Create Date : 2019-11-17 17:46:58
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */

#include <iostream>
#include <cstring>

const int INFTY = 2000000000;

struct Card {
    int number;
    char suit;
};

std::ostream& operator<<(std::ostream& os, const Card &c) {
    os << c.suit << " " << c.number;
    return os;
}

int partition(Card * A, int p, int r) {
    int x = A[r].number;
    int i = p;

    for (int j = p; j < r; j++) {
        if (A[j].number <= x) {
            std::swap(A[j], A[i]);
            i++;
        }
    }
    std::swap(A[r], A[i]);
    return i;
}

void quickSort(Card * A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void merge(Card * A, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    Card L[n1 + 1], R[n2 + 1];
    std::memcpy(L, A + left, sizeof(Card) * n1);
    std::memcpy(R, A + left + n1, sizeof(Card) * n2);
    L[n1] = Card(), R[n2] = Card();
    L[n1].number = INFTY, R[n2].number = INFTY;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].number < R[j].number) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}


void mergeSort(Card * A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main () {
    int n;
    std::cin >> n;
    Card A[n];

    for (int i = 0; i < n; i++) {
        std::cin >> A[i].suit >> A[i].number;
    }

    quickSort(A, 0, n - 1);

    Card B[n];
    std::memcpy(B, A, sizeof(Card) * n);
    mergeSort(B, 0, n - 1);

    //std::cout << "quick sort vs merge sort" << std::endl;
    bool is_stable = true;
    for (int i = 0; i < n; i++) {
        if (A[i].number != B[i].number || A[i].suit != B[i].suit) {
            is_stable = false;
            break;
        }
    }

    if (is_stable) {
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        // std::cout << A[i] << " : " << B[i] << std::endl;
        // std::cout << A[i] << std::endl;
        std::cout << A[i].suit << " " << A[i].number << std::endl;
    }

}
