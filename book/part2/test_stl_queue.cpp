#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> que;

    que.push("red");
    que.push("yellow");
    que.push("yellow");
    que.push("blue");

    std::cout << que.front() << " ";
    que.pop();
    
    std::cout << que.front() << " ";
    que.pop();

    std::cout << que.front() << " ";
    que.pop();

    std::cout << que.front() << " ";
    que.pop();

    std::cout << std::endl;

    return 0;
}
