#include <iostream>
#ifndef NDEBUG
#include <glog/logging.h>
#endif


bool binarySearch(int first, int last, int val, int * S) {
    if (first + 1 == last) {
        return val == S[first];
    }
    int idx = (first + last) / 2;

    if (val < S[idx]) {
        return binarySearch(first, idx, val, S);
    } else if (val > S[idx]) {
        return binarySearch(idx, last, val, S);
    } else if (val == S[idx]) {
        return true;
    }
    return false;
}


int main(int argc, char ** argv) {
#ifndef NDEBUG
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();
#endif

    int n, q;
    std::cin >> n;
    int S[n];
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    std::cin >> q;
    int count = 0;
    for (int i = 0; i < q; i++) {
        int val;
        std::cin >> val;
        if (binarySearch(0, n, val, S)) {
            count++;
        }
    }

    std::cout << count << std::endl;
}
