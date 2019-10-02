#include <iostream>
#include <string>
#include <vector>

struct Data {
    Data() {
        key = -1;
        str = "";
    }

    Data(std::string str) : str(str) {
        key = 0;
        int offset = 1;
        for (auto && c : str) {
            if (c == 'A') {
                key += offset * 1;
            } else if (c == 'C') {
                key += offset * 2;
            } else if (c == 'G') {
                key += offset * 3;
            } else if (c == 'T') {
                key += offset * 4;
            }
            offset *= 5;
        }
    }
    
    int key;
    std::string str;
};

class Dictionary {
  public:
    Dictionary() {
        datas = std::vector<Data>(1000000, Data());
    }
    
    void insert(std::string str) {
        Data data(str);
        int pos = hash(data, 0);
        datas[pos] = data;
    }

    void search(std::string str) {
        Data data(str);
        int pos = hash(data, 0);
        if (datas[pos].str == data.str) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    int hash(const Data &data, const int n_collision) {
        int pos = (data.key % N + n_collision * (N - 1)) % N;
        if (datas[pos].str == data.str || datas[pos].str == "") {
            return pos;
        }
        return hash(data, n_collision + 1);
    }

  private:
    const int N = 1000000;
    std::vector<Data> datas;
};

int main() {
    int n;
    std::cin >> n;

    std::string command, str;
    Dictionary dict = Dictionary();
    for (int i = 0; i < n; i++) {
        std::cin >> command >> str;
        if (command == "insert") {
            dict.insert(str);
        } else if (command == "find") {
            dict.search(str);
        }
    }
}
