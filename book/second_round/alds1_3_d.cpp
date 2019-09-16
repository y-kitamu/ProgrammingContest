#include <iostream>
#include <memory>

struct Shed {
    bool is_shed = false;
    int left_idx, right_idx;
    int left_val, right_val;
    int sum = 0;
    std::shared_ptr<Shed> prev, next;
};

class ShedMap {
  public:
    ShedMap() {
        head = std::make_shared<Shed>();
        tail = std::make_shared<Shed>();
        current = std::make_shared<Shed>();
        head->next = current;
        tail->prev = current;
        current->prev = head;
        current->next = tail;
    }

    void createNewShed() {
        std::shared_ptr<Shed> new_shed = std::make_shared<Shed>();
        current->next = new_shed;
        tail->prev = new_shed;
        new_shed->prev = current;
        new_shed->next = tail;
    }

    void map_down(int idx, int val) {
        if (!current->is_shed) {
            current->is_shed = true;
            current->left_idx = idx;
            current->left_val = val;
        }
    }

    void map_up(int idx, int val) {
        if (current->is_shed) {
            if (val == current->left_val) {
                current->is_shed = false;
                current->right_idx = idx;
                current->right_val = val;
                
                createNewShed();
            } else if (val > current->left_val) {
                auto node = current->prev;
                while (node != head) {
                    if (node->left_val >= val) {
                        current = node;
                        current->next = tail;
                        break;
                    }
                }
            }
            current->right_idx = idx;
            current->right_val = val;
        }
    }

    void calc_area(std::string str) {
        auto shed = head->next;
        int count = 0, total = 0;
        while (shed != tail) {
            std::cout << shed->left_idx << " -> " << shed->right_idx << std::endl;
            if (!shed->is_shed) {
                continue;
            }

            int max_height = std::max(shed->left_val, shed->right_val);
            int height = shed->left_val;
            for (int i = shed->left_idx; i <= shed->right_idx; i++) {
                if (str[i] == '\\') {
                    height--;
                    shed->sum += (max_height - height) * 2 - 1;
                } else if (str[i] == '/') {
                    shed->sum += (max_height - height) * 2 - 1;
                    height++;
                } else {
                    shed->sum += (max_height - height) * 2;
                }
                // std::cout <<  i << ", " << max_height << " " << height << " " << shed->sum << std::endl;
            }
            shed->sum /= 2;
            total += shed->sum;
            count++;
            shed = shed->next;
        }

        std::cout << total << std::endl;
        std::cout << count;
        shed = head->next;
        while (shed != tail) {
            std::cout << " " << shed->sum;
            shed = shed->next;
        }
        std::cout << std::endl;
    }

  private:
    std::shared_ptr<Shed> head, tail, current;
};

int main() {
    std::string str;
    std::cin >> str;

    ShedMap map;

    int height = 0;
    for (int i = 0; i < (int)str.length(); i++) {
        if (str[i] == '\\') {
            map.map_down(i, height);
            height--;
        } else if (str[i] == '/') {
            map.map_up(i, height);
            height++;
        }
    }

    map.calc_area(str);
}
