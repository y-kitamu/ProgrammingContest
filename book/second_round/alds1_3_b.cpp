#include <iostream>
#include <string>

struct Process {
    Process() = default;
    Process(std::string name, int time) : name(name), time(time) {};
    std::string name;
    int time;
};

class Queue {
  public:
    void initialize() {
        head = tail = 0;
    }
    
    void enqueue(Process x) {
        queue[tail] = x;
        tail = (tail + 1) % len;
    }

    Process dequeue() {
        Process val = queue[head];
        head = (head + 1) % len;
        return val;
    }

    bool isEmpty() {
        return head == tail;
    }

  private:
    static const int len = 100000;
    int head, tail;
    Process queue[len];
};

int main() {
    int n, q;
    std::cin >> n >> q;

    Queue qu;

    for (int i = 0; i < n; i++) {
        std::string name;
        int time;
        std::cin >> name >> time;
        qu.enqueue(Process(name, time));
    }

    int elapsed = 0;
    while (!qu.isEmpty()) {
        Process p = qu.dequeue();
        if (p.time <= q) {
            elapsed += p.time;
            std::cout << p.name << " " << elapsed << std::endl;
        } else {
            elapsed += q;
            qu.enqueue(Process(p.name, p.time - q));
        }
    }

    // int elapsed = 0;
    // bool loop = true;
    // while (loop) {
    //     loop = false;
    //     for (int i = 0; i < n; i++) {
    //         if (time[i] == 0) {
    //             continue;
    //         }
    //         loop = true;
    //         if (time[i] <= q) {
    //             elapsed += time[i];
    //             std::cout << name[i] << " " << elapsed << std::endl;
    //             time[i] = 0;
    //         } else {
    //             time[i] -= q;
    //             elapsed += q;
    //         }
    //     }
    // }
    
}
