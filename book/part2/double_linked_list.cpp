#include <iostream>


class DoublyLinkedList {
public:
    DoublyLinkedList() {
        dllist = new int[max_len];
    }

    ~DoublyLinkedList() {
        delete dllist;
    }
    
    void insert(int n) {
        if (head == 0) {
            head = max_len - 1;
            dllist[head] = n;
        } else {
            dllist[--head] = n;
        }
    }

    void deleteKey(int n) {
        int position = head;
        while (true) {
            if (dllist[position] == n) break;
            position = position == max_len - 1 ? 0 : position + 1;
        }

        while (position != tail) {
            std::swap(dllist[position], dllist[(position + 1) % max_len]);
            position = position == max_len - 1 ? 0 : position + 1; 
        }
        tail = tail == 0 ? max_len - 1 : tail - 1;
    }

    void deleteFirst() {
        head = head == max_len - 1 ? 0 : head + 1;
    }

    void deleteLast() {
        tail = tail == 0 ? max_len - 1 : tail - 1;
    }

    void show_elements() {
        int position = head;
        while (position != tail) {
            std::cout << dllist[position];
            if ((position + 1) % max_len != tail) {
                std::cout << " ";
            }
            position = position == max_len - 1 ? 0 : position + 1;
        }
        std::cout << std::endl;
    }
    
    static const int max_len = 10e6;
    int head = 0;
    int tail = 0;
    int *dllist;
};

int main(int argc, char ** argv) {
    int n = 1;
    std::cin >> n;

    DoublyLinkedList dll = DoublyLinkedList();
    
    for (int i = 0; i < n; i++) {
        char command[11];
        scanf("%s", command);
        if (std::string(command) == "insert") {
            int val;
            scanf("%d", &val);
            dll.insert(val);
        } else if (std::string(command) == "delete") {
            int val;
            scanf("%d", &val);
            dll.deleteKey(val);
        } else if (std::string(command) == "deleteFirst") {
            dll.deleteFirst();
        } else if (std::string(command) == "deleteLast") {
            dll.deleteLast();
        }
    }
    dll.show_elements();
}
