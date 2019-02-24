#include <iostream>
#include <vector>
#include <memory>

int N;

void maxHeapify(std::shared_ptr<std::vector<int>> A, int i) {
    int l = i * 2, r = i * 2 + 1;
    int largest;
    
    if (l <= N && (*A)[l] > (*A)[i]) largest = l;
    else largest = i;

    if (r <= N && (*A)[r] > (*A)[largest]) largest = r;

    if (largest != i) {
        std::swap((*A)[largest], (*A)[i]);
        maxHeapify(A, largest);
    }
}



int main() {
    std::cin >> N;

    std::shared_ptr<std::vector<int>> heap = std::make_shared<std::vector<int>>(N + 1);

    for (int i = 1; i <= N; i++) {
        std::cin >> (*heap)[i];
    }

    for (int i = N / 2; i >= 1; i--) {
        maxHeapify(heap, i);
    }

    for (int i = 1; i <= N; i++) {
        std::cout << " " << (*heap)[i];
    }
    std::cout << std::endl;
}
