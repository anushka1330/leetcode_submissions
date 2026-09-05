class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        for (char c : s) {
            freq[c]++;
        }
        int ans = 0;
        bool hasOdd = false;

        for (int f : freq) {
            ans += (f / 2) * 2;
            if (f % 2 == 1) {
                hasOdd = true;
            }
        }
        if (hasOdd) {
            ans++;
        }
        return ans;
    }
};