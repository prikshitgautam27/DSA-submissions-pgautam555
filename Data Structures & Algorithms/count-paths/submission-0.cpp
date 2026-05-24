class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        int total_moves = m + n - 2;
        int down_moves = m - 1;

        // Fix: Properly compute the combination formula factor by factor
        for (int i = 1; i <= down_moves; i++) {
            result = result * (total_moves - down_moves + i) / i;
        }

        return (int)result;
    }
};
