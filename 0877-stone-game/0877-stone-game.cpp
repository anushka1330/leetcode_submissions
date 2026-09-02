class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] = maximum score difference
        // current player can achieve from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // Base case: one pile
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        // Build for increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                // Take left pile or right pile
                int takeLeft = piles[i] - dp[i + 1][j];
                int takeRight = piles[j] - dp[i][j - 1];

                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        // Positive difference means Alice wins
        return dp[0][n - 1] > 0;
    }
};