#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int pow = 1;
    long long int num = 0;
    long long int cnt = 0;
    while (N >= pow * 1000) {
        cnt += (pow * 1000 - pow) * num;
        pow *= 1000;
        num++;
    }

    long long int res = N / pow - 1;
    long long int mod = N % pow;
    cnt += res * pow * num;
    cnt += (mod + 1) * num;
    std::cout << cnt << std::endl;
}
