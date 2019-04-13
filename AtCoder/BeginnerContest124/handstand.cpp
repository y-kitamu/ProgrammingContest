#include <iostream>
#include <string>
#include <bitset>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;

    std::vector<std::pair<char, int>> sequence;

    int count = 1;
    for (auto itr = S.begin() + 1; itr != S.end(); itr++) {
        if (itr[-1] == itr[0]) {
            count++;
        } else {
            sequence.push_back(std::make_pair(itr[-1], count));
            count = 1;
        }
    }
    sequence.push_back(std::make_pair(*(S.end() - 1), count));

    int seq_size = sequence.size();
    int seq = 0, idx = 0, start_idx = 0;
    for (int cnt = 0; cnt < K && idx < seq_size; idx++) {
        seq += sequence[idx].second;
        if (sequence[idx].first == '0') {
            cnt++;
        }
        if (cnt == K && idx < seq_size - 1) {
            idx++;
            seq += sequence[idx].second;
            idx++;
            break;
        }
    }

    int max_seq = seq;
    for (; idx < seq_size; idx += 2) {
        if (sequence[start_idx].first == '0') {
            seq += sequence[idx].second + sequence[idx + 1].second - sequence[start_idx].second;
            start_idx++;
        } else {
            if (idx < seq_size - 1) {
                seq += sequence[idx].second + sequence[idx + 1].second
                    - sequence[start_idx].second - sequence[start_idx + 1].second;
            } else {
                seq += sequence[idx].second
                    - sequence[start_idx].second - sequence[start_idx + 1].second;
            }
            start_idx += 2;
        }
        if (seq > max_seq) {
            max_seq = seq;
        }
    }

    std::cout << max_seq << std::endl;
}
