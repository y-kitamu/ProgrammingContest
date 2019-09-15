#include <iostream>
#include <sstream>

int main() {
    int stack[300];
    int *ptr = stack;

    std::string input;
    std::getline(std::cin, input);
    std::stringstream sin(input);

    std::string val;
    while (sin >> val) {
        std::cout << val << " ";

        if (val == "+") {
            ptr[-2] = ptr[-2] + ptr[-1];
            ptr--;
        } else if (val == "-") {
            ptr[-2] = ptr[-2] - ptr[-1];
            ptr--;
        } else if (val == "*") { 
            ptr[-2] = ptr[-2] * ptr[-1];
            ptr--;
        } else {
            ptr[0] = std::atoi(val.c_str());
            ptr++;
        }
        std::cout << ptr[-1] << std::endl;
    }

    std::cout << ptr[-1] << std::endl;
}
