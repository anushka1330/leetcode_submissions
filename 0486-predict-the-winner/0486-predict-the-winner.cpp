class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n));

        // Base case: one element
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // Build for larger subarrays
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                int takeLeft = nums[l] - dp[l + 1][r];
                int takeRight = nums[r] - dp[l][r - 1];

                dp[l][r] = max(takeLeft, takeRight);
            }
        }

        // Player 1 wins or ties if the score difference >= 0
        return dp[0][n - 1] >= 0;
    }
};