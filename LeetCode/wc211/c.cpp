#include <bits/stdc++.h>


class Solution {
public:
    std::vector<std::pair<int, int>> players;
    std::vector<int> max_scores;
    int n_players;

    int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) {
        n_players = scores.size();

        players = std::vector<std::pair<int, int>>(n_players);
        for (int i = 0; i < n_players; i++) {
            players[i].first = scores[i];
            players[i].second = ages[i];
        }

        std::sort(players.begin(), players.end(), [] (auto& lhs, auto& rhs) {
            if (lhs.first > rhs.first) {
                return true;
            }
            if (lhs.first < rhs.first) {
                return false;
            }
            return lhs.second > rhs.second;
        });

        int max_score = 0;
        max_scores = std::vector<int>(n_players, -1);
        for (int i = 0; i < n_players; i++) {
            max_score = std::max(search(i), max_score);
        }
        return max_score;
    }

    int search(int idx) {
        if (max_scores[idx] != -1) {
            return max_scores[idx];
        }
        int score = players[idx].first;
        std::vector<int> cand;
        for (int i = idx + 1; i < n_players; i++) {
            if (players[idx].second >= players[i].second) {
                cand.emplace_back(i);
            }
        }
        for (auto i : cand) {
            score = std::max(score, search(i) + players[idx].first);
        }
        max_scores[idx] = score;
        return score;
    }
};


int main() {
    std::vector scores {9, 2, 8, 8, 2};
    std::vector ages {4, 1, 3, 3, 5};
    std::cout << Solution().bestTeamScore(scores, ages) << std::endl;;
}
