#include <iostream>

int loadLuggage(int max_weight, int track_num, int * lugs, int lugs_num) {
    int lug_idx = 0;
    for (int i = 0; i < track_num; i++) {
        int weight = 0;
        while (weight + lugs[lug_idx] <= max_weight) {
            weight += lugs[lug_idx];
            lug_idx++;
            if (lug_idx == lugs_num) {
                return lug_idx;
            }
        }
    }
    return lug_idx;
}

int binarySearch(int min_weight, int max_weight, int track_num, int * lugs, int lugs_num) {
    if (min_weight + 1 >= max_weight) {
        if (loadLuggage(min_weight, track_num, lugs, lugs_num) == lugs_num) {
            return min_weight;
        } else {
            return max_weight;
        }
    }
    
    int weight = (min_weight + max_weight) / 2;
    int track_weight = -1;
    if (loadLuggage(weight, track_num, lugs, lugs_num) == lugs_num) {
        track_weight = binarySearch(min_weight, weight, track_num, lugs, lugs_num);
    } else {
        track_weight = binarySearch(weight, max_weight, track_num, lugs, lugs_num);
    }
    return track_weight;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int w[n], sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
        sum += w[i];
    }

    int ans = binarySearch(0, sum, k, w, n);

    std::cout << ans << std::endl;
}
