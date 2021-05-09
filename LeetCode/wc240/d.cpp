#include <bits/stdc++.h>


class Solution {
  public:
    bool has_cycle(int idx, std::vector<bool>& seen, std::vector<bool>& finished,
                   const std::vector<std::vector<int>> ll) {
        if (seen[idx]) {
            return !finished[idx];
        }
        seen[idx] = true;
        for (auto& next : ll[idx]) {
            if (seen[next]) {
                if (!finished[next]) {
                    return true;
                }
            } else if (has_cycle(next, seen, finished, ll)) {
                return true;
            }
        }
        finished[idx] = true;
        return false;
    }

    int largestPathValue(std::string colors, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> linked_list(colors.length());
        for (auto& edge : edges) {
            linked_list[edge[0]].emplace_back(edge[1]);
        }

        std::vector<std::vector<int>> counts(colors.length(), std::vector<int>(26, 0));

        std::vector<bool> flag(colors.length(), false);
        std::vector<bool> seen(colors.length(), false), finished(colors.length(), false);

        for (int i = 0; i < colors.length(); i++) {
            if (!seen[i] && has_cycle(i, seen, finished, linked_list)) {
                return -1;
            }
            if (flag[i]) {
                continue;
            }
            update(i, flag, counts, colors, linked_list);
        }

        int max = 0;
        for (auto& vals : counts) {
            for (auto& val : vals) {
                max = std::max(max, val);
            }
        }
        return max;
    }

    void update(int idx, std::vector<bool>& flag, std::vector<std::vector<int>>& counts,
                const std::string& colors, const std::vector<std::vector<int>>& ll) {
        if (flag[idx]) {
            return;
        }
        for (auto& child : ll[idx]) {
            if (!flag[child]) {
                update(child, flag, counts, colors, ll);
            }
            for (int i = 0; i < 26; i++) {
                counts[idx][i] = std::max(counts[idx][i], counts[child][i]);
            }
        }
        flag[idx] = true;
        counts[idx][colors[idx] - 'a']++;
    }
};


int main() {}
