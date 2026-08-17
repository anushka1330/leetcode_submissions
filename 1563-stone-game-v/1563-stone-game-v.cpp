class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                for (int mid = l; mid < r; mid++) {
                    long long leftSum = prefix[mid + 1] - prefix[l];
                    long long rightSum = prefix[r + 1] - prefix[mid + 1];

                    if (leftSum < rightSum) {
                        dp[l][r] = max(dp[l][r],
                                      (int)(leftSum + dp[l][mid]));
                    }
                    else if (leftSum > rightSum) {
                        dp[l][r] = max(dp[l][r],
                                      (int)(rightSum + dp[mid + 1][r]));
                    }
                    else {
                        dp[l][r] = max(dp[l][r],
                                      (int)(leftSum + max(dp[l][mid],
                                                         dp[mid + 1][r])));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};