#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    std::stack<std::string> stack;

    int count = 0;
    std::string s = "";
    for (int i = 0; i < N; i++) {
        if (S[i] == 'f') {
            if (s.length() > 0) {
                stack.push(s);
            }
            s = "f";
        } else if (S[i] == 'o') {
            if (s.length() == 1) {
                s = "fo";
            } else if (s.length() == 0 && !stack.empty() && stack.top().length() == 1) {
                stack.pop();
                stack.push("fo");
                s = "";
            } else {
                stack = std::stack<std::string>();
                s = "";
            }
        } else if (S[i] == 'x') {
            if (s.length() == 2) {
                count++;
                s = "";
            } else if (s.length() == 0 && !stack.empty() && stack.top().length() == 2) {
                stack.pop();
                count++;
            } else {
                stack = std::stack<std::string>();
                s = "";
            }
        } else {
            std::stack<std::string>().swap(stack);
            s = "";
        }
    }
    std::cout << N - count * 3 << std::endl;
}
