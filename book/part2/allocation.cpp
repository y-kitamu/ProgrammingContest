#include <iostream>

int combination(int n, int k, int min_idx, int idx, int *idices, int *w) {
    if (k == 0) {
        int max_weight = 0;
        // std::cout << "idices = " ;
        for (int i = 0; i < idx; i++) {
            int weight = 0;
            for (int j = idices[i]; j < idices[i + 1]; j++) {
                weight += w[j];
            }
            if (max_weight < weight) max_weight = weight;
            // std::cout << idices[i] << " ";
        }
        // std::cout << ", max_weight = " << max_weight << std::endl;
        return max_weight;
    }

    long int min_weight = 1e10;
    for (int i = min_idx; i < n - k + 1; i++) {
        idices[idx] = i;
        int weight = combination(n, k - 1, i + 1, idx + 1, idices, w);
        if (weight < min_weight) min_weight = weight;
    }

    return min_weight;
}


int f(int P, int n, int k, int *w) {
    int weight = 0, track_num = 0, idx = 0;
    while (track_num < k) {
        weight = 0;
        for (; idx < n; idx++) {
            if (P >= weight + w[idx]) {
                weight += w[idx];
            } else {
                track_num++;
                break;
            }
        }
        if (idx == n) {
            break;
        }
    }
    return idx;
}


int binary_search(int n, int k, int *w, int total) {
    int left = 0;
    int right = total;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        int val = f(mid, n, k, w);
        
        if (val == n) {
            right = mid;
        } else if (val < n) {
            left = mid + 1;
        }
    }

    int idx = right;
    while (n <= f(idx - 1, n, k, w)) {
        idx--;
    }

    return idx;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int w[n], total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", w + i);
        total += w[i];
    }

    int weight = binary_search(n, k, w, total);

    std::cout << weight << std::endl;
}
