#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void answer1(std::vector<int> scores) {

    for (int i = 0; i < 3; i++) {
        int idx = 0;
        int max_score = scores[0], max_idx = 0;
        
        for (auto && score : scores) {
            if (score > max_score) {
                max_score = score;
                max_idx = idx;
            }
            idx++;
        }
        
        std::cout << max_score << " ";
        scores.erase(scores.begin() + max_idx);
    }
    std::cout << std::endl;
}

void answer2(std::vector<int> scores) {
    std::sort(scores.begin(), scores.end(), [](const auto &lhs, const auto &rhs) { return lhs > rhs; });

    std::cout << scores[0] << " " << scores[1] << " " << scores[2] << std::endl;
}


void answer3(std::vector<int> scores) {
    std::vector<int> score_histogram(101, 0);
    for (auto && score : scores) {
        score_histogram[100 - score]++;
    }

    int count = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < score_histogram[i]; j++) {
            std::cout << 100 - i << " ";
            count++;
            if (count == 3) {
                break;
            }
        }
        if (count == 3) {
            break;
        }
    }
    std::cout << std::endl;
}


int main(int argc, char ** argv) {
    std::vector<int> scores {25, 36, 4, 55, 71, 18, 0, 71, 89, 65};
    
    answer1(scores);
    answer2(scores);
    answer3(scores);
}
