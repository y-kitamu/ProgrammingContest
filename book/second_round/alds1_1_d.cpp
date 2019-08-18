#include <iostream>


int main() {
    int N;
    std::cin >> N;

    int r_in, max_val, min_val, diff;
    bool is_max_val_set = false;
    std::cin >> min_val >> max_val;
    diff = max_val - min_val;
    min_val = std::min(max_val, min_val);
    
    for (int i = 2; i < N; i++) {
        std::cin >> r_in;
        if (!is_max_val_set) {
            max_val = r_in;
            diff = std::max(diff, max_val - min_val);
            is_max_val_set = true;
        }
        
        if (r_in > max_val) {
            max_val = r_in;
            diff = std::max(diff, max_val - min_val);
        } else if (r_in < min_val) {
            min_val = r_in;
            is_max_val_set = false;
        }
    }

    std::cout << diff << std::endl;
}
