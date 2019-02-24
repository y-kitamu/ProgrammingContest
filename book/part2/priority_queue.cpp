#include <iostream>
#include <vector>

class PriorityQueue {
public:
    void insert(int key) {
        if (queue_num < (int)queue.size()) queue[queue_num] = key;
        else queue.push_back(key);
        int k = queue_num;
        while (k > 0) {
            if (queue[(k - 1) / 2] < queue[k]) std::swap(queue[(k - 1) / 2], queue[k]);
            k = (k - 1) / 2;
        }
        queue_num++;
    }

    void maxHeapify(int k) {
        int left = k * 2 + 1;
        int right = k * 2 + 2;
        int largest;
        if (left < queue_num && queue[left] > queue[k]) largest = left;
        else largest = k;
        if (right < queue_num && queue[right] > queue[largest]) largest = right;

        if (k != largest) {
            std::swap(queue[k], queue[largest]);
            maxHeapify(largest);
        }
    }

    int extractMax() {
        int val = queue[0];
        queue[0] = queue[queue_num - 1];
        queue_num--;

        maxHeapify(0);
        return val;
    }

    std::vector<int> queue;
    int queue_num = 0;
};


int main() {
    PriorityQueue queue = PriorityQueue();
    
    for (;;) {
        std::string command;
        std::cin >> command;

        if (command == "insert") {
            int key;
            std::cin >> key;
            queue.insert(key);
        } else if (command == "extract") {
            std::cout << queue.extractMax() << std::endl;;
        } else if (command == "end") {
            break;
        }
    }
}
