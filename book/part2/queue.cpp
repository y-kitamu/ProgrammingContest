#include <iostream>

void roundRobinSchedule(int *A, std::string *Name, int N, int quantum) {
    bool is_finished = false;
    int elapsed_time = 0;
    
    while (!is_finished) {
        is_finished = true;
        
        for (int i = 0; i < N; i++) {
            if (A[i] == 0) continue;
            if (A[i] <= quantum) {
                elapsed_time += A[i];
                A[i] = 0;
                std::cout << Name[i] << " " << elapsed_time << std::endl;
            } else {
                A[i] -= quantum;
                elapsed_time += quantum;
                is_finished = false;
            }
        }
    }
}

int main(int argc, char ** argv) {
    int queue_num, quantum;
    std::cin >> queue_num >> quantum;

    std::string queue_name[queue_num];
    int queue_time[queue_num];
    for (int i = 0; i < queue_num; i++) {
        std::cin >> queue_name[i] >> queue_time[i];
    }

    roundRobinSchedule(queue_time, queue_name, queue_num, quantum);
    
}
