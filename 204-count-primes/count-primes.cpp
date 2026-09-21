class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Start count assuming all odd numbers >= 3 are prime candidates
        int count = n / 2; // includes 2, 3, 5, 7, ... up to n-1

        // isComposite[i] tracks odd numbers: (2 * i + 1)
        vector<bool> isComposite(n / 2, false);

        for (int i = 3; i * i < n; i += 2) {
            if (!isComposite[i / 2]) {
                // Step by 2 * i to mark only odd multiples (3i, 5i, 7i, ...)
                for (int j = i * i; j < n; j += 2 * i) {
                    if (!isComposite[j / 2]) {
                        isComposite[j / 2] = true;
                        count--; // Decrement candidate count as we find composites
                    }
                }
            }
        }

        return count;
    }
};