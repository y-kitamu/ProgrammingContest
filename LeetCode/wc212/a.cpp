#include <bits/stdc++.h>

class Solution {
public:
    char slowestKey(std::vector<int>& releaseTimes, std::string keysPressed) {
        int seq_length = releaseTimes.size();

        char max_char = keysPressed[0];
        int longest = releaseTimes[0];
        for (int i = 1; i < seq_length; i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if (longest < duration) {
                longest = duration;
                max_char = keysPressed[i];
            } else if (longest == duration) {
                max_char = std::max(max_char, keysPressed[i]);
            }
        }
        return max_char;
    }
};


int main() {

}
