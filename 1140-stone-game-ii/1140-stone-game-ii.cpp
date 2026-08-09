class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        // If we can take all remaining piles.
        if (2 * M >= n - i)
            return dp[i][M] = suffix[i];

        int best = 0;

        // Take X piles, where 1 <= X <= 2*M
        for (int X = 1; X <= 2 * M; ++X) {
            int opponent = solve(i + X, max(M, X));

            // Total remaining stones - opponent's maximum.
            int current = suffix[i] - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = sum of piles[i...n-1]
        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};