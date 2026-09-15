class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[l][r] = whether s[l..r] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                if (len == 1) {
                    pal[l][r] = true;
                }
                else if (len == 2) {
                    pal[l][r] = (s[l] == s[r]);
                }
                else {
                    pal[l][r] = (s[l] == s[r] && pal[l + 1][r - 1]);
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // in s[0..i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Don't end a palindrome at i-1
            dp[i] = dp[i - 1];

            // Try every palindrome ending at i-1
            for (int l = 0; l <= i - k; l++) {
                if (pal[l][i - 1]) {
                    dp[i] = max(dp[i], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};