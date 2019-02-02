#include <iostream>
#include <stack>

int main(int argc, char ** argv) {
    std::stack<int> st;

    st.push(3);
    st.push(7);
    st.push(1);
    std::cout << st.size() << " ";

    std::cout << st.top() << " ";
    st.pop();
    
    std::cout << st.top() << " ";
    st.pop();
    
    std::cout << st.top() << " ";
    st.pop();

    std::cout << std::endl;

    return 0;
}
