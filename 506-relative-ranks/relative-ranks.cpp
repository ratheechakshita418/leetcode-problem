class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();
        std::vector<std::pair<int, int>> score_with_index(n);
        for (int i = 0; i < n; ++i) {
            score_with_index[i] = {score[i], i};
        }
        std::sort(score_with_index.rbegin(), score_with_index.rend());
        std::vector<std::string> result(n);
        for (int i = 0; i < n; ++i) {
            int orig_idx = score_with_index[i].second;
            if (i == 0) {
                result[orig_idx] = "Gold Medal";
            } else if (i == 1) {
                result[orig_idx] = "Silver Medal";
            } else if (i == 2) {
                result[orig_idx] = "Bronze Medal";
            } else {
                result[orig_idx] = std::to_string(i + 1);
            }
        }
        return result;
    }
};