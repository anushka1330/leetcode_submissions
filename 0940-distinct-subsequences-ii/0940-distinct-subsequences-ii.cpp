class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        // dp = number of distinct subsequences including empty subsequence
        long long dp = 1;
        
        // last[c] = dp value before the previous occurrence of c
        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';
            
            long long newDp = (2 * dp % MOD - last[idx] + MOD) % MOD;
            
            last[idx] = dp;
            dp = newDp;
        }

        // Exclude the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};