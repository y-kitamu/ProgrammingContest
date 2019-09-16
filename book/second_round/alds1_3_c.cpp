#include <iostream>
#include <memory>
#include <glog/logging.h>

class DLL {
  public:
    DLL() {
        head = tail;
    }

    void insert(int x) {
        head = (head - 1 + len) % len;
        list[head] = x;
    }

    void del(int x) {
        bool found = false;
        int i = head;
        for (; i != tail; i++) {
            if (list[i] == x) {
                i++;
                found = true;
                break;
            }
            if (i == len - 1) {
                i = -1;
            }
        }

        if (found) {
            for (; i != tail; i++) {
                list[i - 1] = list[i];
                if (i == len - 1) {
                    i = -1;
                }
            }
            tail = (tail - 1 + len) % len;
        }
    }

    void delFirst() {
        head = (head + 1) % len;
    }

    void delLast() {
        tail = (tail - 1 + len) % len;
    }

    void print_key() {
        // std::cout << head << " " << tail << std::endl;
        if (head == tail) {
            return;
        }
        std::cout << list[head];
        for (int i = (head + 1) % len; i != tail; i++) {
            std::cout <<  " " << list[i];
            if (i == len - 1) {
                i = -1;
            }
        }
        std::cout << std::endl;
    }

  private:
    static const int len = 1000000;
    int head = 0, tail = 0;
    int list[len];
};

struct Node {
    Node() = default;
    Node(int val) : val(val) {}
    int val;
    std::shared_ptr<Node> prev, next;
};


class DLL2 {
  public:
    DLL2() {
        head = std::make_shared<Node>();
        tail = std::make_shared<Node>();
        head->next = tail;
        tail->prev = head;
    }
    
    void insert(int val) {
        std::shared_ptr<Node> n = std::make_shared<Node>(val);
        n->prev = head;
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
    }

    void del(int val) {
        if (head->next == tail) {
            return;
        }
        std::shared_ptr<Node> n = head->next;
        while (n != tail) {
            if (n->val == val) {
                n->prev->next = n->next;
                n->next->prev = n->prev;
                break;
            }
            n = n->next;
        }
    }

    void delFirst() {
        head->next = head->next->next;
        head->next->prev = head;
    }

    void delLast() {
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
    }

    void print_key() {
        if (head->next == tail)  {
            return;
        }
        std::shared_ptr<Node> n = head->next;
        while (n->next != tail) {
            std::cout << n->val << " ";
            n = n->next;
        }
        std::cout << n->val << std::endl;
    }

  private:
    std::shared_ptr<Node> head, tail;
};


int main(int argc, char ** argv) {
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();
    
    int n;
    DLL2 dll = DLL2();
    std::string command;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        dll.print_key();
        std::cin >> command;

        if (command == "insert") {
            int val;
            std::cin >> val;
            dll.insert(val);
        } else if (command == "delete") {
            int val;
            std::cin >> val;
            dll.del(val);
        } else if (command == "deleteFirst") {
            dll.delFirst();
        } else if (command == "deleteLast") {
            dll.delLast();
        }
    }
    dll.print_key();
}
