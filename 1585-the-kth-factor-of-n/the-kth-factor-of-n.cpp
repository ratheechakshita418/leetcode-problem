class Solution {
public:
    int kthFactor(int n, int k) {
        // First pass: find factors up to sqrt(n) in increasing order
        int d = 1;
        for (; d * d <= n; ++d) {
            if (n % d == 0) {
                k--;
                if (k == 0) return d;
            }
        }
        
        // Adjust for exact square root to avoid double counting
        d--;
        if (d * d == n) {
            d--;
        }
        
        // Second pass: iterate backwards to find paired factors in increasing order
        for (; d >= 1; --d) {
            if (n % d == 0) {
                k--;
                if (k == 0) return n / d;
            }
        }
        
        return -1;
    }
};