#include <iostream>
#include <stack>
#include <sstream>
#include <cstdio>

int main(int argc, char ** argv) {
    std::stack<int> st;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream sin(input);
    
    std::string s;
    while (sin >> s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            
            if(s =="+") {
                st.push(val1 + val2);
            } else if (s == "-") {
                st.push(val2 - val1);
            } else if (s == "*") {
                st.push(val1 * val2);
            } else {
                st.push(val2 / val1);
            }
        } else {
            std::stringstream ss(s);
            int val;
            ss >> val;
            st.push(val);
        }
    }
    std::cout << st.top() << std::endl;
}
