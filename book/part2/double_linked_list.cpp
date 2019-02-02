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

    void showElements() {
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


struct Node {
    int value;
    Node *prev, *next;
};


class DoublyLinkedList2 {
public:
    DoublyLinkedList2() {
        nil = new Node;
        nil->prev = nil;
        nil->next = nil;
    }

    void insert(int x) {
        Node *new_node = new Node;
        new_node->value = x;
        new_node->prev = nil;
        new_node->next = nil->next;
        nil->next->prev = new_node;
        nil->next = new_node;
    }
    
    Node* search(int x) {
        Node *cur = nil->next;
        while (cur != nil && cur->value != x) {
            cur = cur->next;
        }
        return cur;
    }

    void deleteNode(Node *t) {
        if (t == nil) return;
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
    }
    
    void deleteFirst() {
        deleteNode(nil->next);
    }

    void deleteLast() {
        deleteNode(nil->prev);
    }

    void deleteKey(int x) {
        deleteNode(search(x));
    }

    void showElements() {
        Node *cur = nil->next;
        while (cur != nil) {
            std::cout << cur->value;
            if (cur->next != nil) {
                std::cout << " ";
            }
            cur = cur->next;
        }
        std::cout << std::endl;
    }
    
    Node *nil;
};


int main(int argc, char ** argv) {
    int n = 1;
    std::cin >> n;

    DoublyLinkedList2 dll = DoublyLinkedList2();
    
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
    dll.showElements();
}
