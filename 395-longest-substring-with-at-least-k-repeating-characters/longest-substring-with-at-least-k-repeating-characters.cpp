class Solution {
public:
    int longestSubstring(std::string s, int k) {
        int n = s.length();
        if (n == 0 || k > n) return 0;
        if (k <= 1) return n;
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int split_idx = 0;
        while (split_idx < n && freq[s[split_idx]] >= k) {
            split_idx++;
        }
        if (split_idx == n) return n;
        int left = longestSubstring(s.substr(0, split_idx), k);
        while (split_idx < n && freq[s[split_idx]] < k) {
            split_idx++;
        }
        int right = (split_idx < n) ? longestSubstring(s.substr(split_idx), k) : 0;
        return std::max(left, right);
    }
};