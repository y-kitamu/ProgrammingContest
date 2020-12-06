#include <bits/stdc++.h>

class Solution {
public:
    std::string interpret(std::string command) {
        std::string goal = "";
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                goal += "G";
            } else if (command[i] == '(' && command[i + 1] == ')') {
                goal += "o";
            } else if (command[i] == '(' && command[i + 1] == 'a'){
                goal += "al";
            }
        }
        return goal;
    }
};


int main() {

}
