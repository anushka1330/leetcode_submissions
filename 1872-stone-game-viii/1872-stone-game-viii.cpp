class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        vector<long long> dp(n);

        // When only one stone remains, the game ends.
        dp[n - 1] = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            dp[i] = max(prefix[i] - dp[i + 1], dp[i + 1]);
        }

        return (int)dp[1];
    }
};