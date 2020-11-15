#include <bits/stdc++.h>


class OrderedStream {
public:

    OrderedStream(int n) {
        values = std::vector<std::string>(n);
        flag = std::vector<bool>(n, false);
        ptr = 0;
    }

    std::vector<std::string> insert(int id, std::string value) {
        id--;
        values[id] = value;
        flag[id] = true;

        std::vector<std::string> res;
        if (id == ptr) {
            while (flag[ptr]) {
                res.emplace_back(values[ptr]);
                ptr++;
            }
        }
        return res;
    }

    std::vector<bool> flag;
    std::vector<std::string> values;
    int ptr;
};


int main() {

}
