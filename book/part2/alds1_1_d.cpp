#include <vector>
#include <iostream>


int main(int argc, char ** argv) {
    int time_step_num;
    std::cin >> time_step_num;

    std::vector<int> Rt(time_step_num);

    for (int i = 0; i < time_step_num; i++) {
        std::cin >> Rt[i];
    }

    int max_diff = Rt[1] - Rt[0];
    int min_idx = Rt[1] > Rt[0] ? 0 : 1;
    
    for (int i = 2; i < time_step_num; i++) {
        
        int diff = Rt[i] - Rt[min_idx];
        // std::cout << "i = " << i << ", " << diff << std::endl;
        
        if (max_diff < diff) {
            max_diff = diff;
        }

        if (Rt[i] < Rt[min_idx]) {
            min_idx = i;
        }
    }

    std::cout << max_diff << std::endl;
}
