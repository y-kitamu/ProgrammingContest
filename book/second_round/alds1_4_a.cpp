#include <iostream>
#ifndef NDEBUG
#include <glog/logging.h>
#endif

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
        for (int j = 0; j < n; j++) {
            if (S[j] == val) {
                count++;
                break;
            }
        }
    }

    std::cout << count << std::endl;
}
