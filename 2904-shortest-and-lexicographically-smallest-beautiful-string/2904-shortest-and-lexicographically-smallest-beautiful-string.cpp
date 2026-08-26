class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    ones++;

                // Exactly k ones
                if (ones == k) {
                    int len = j - i + 1;
                    string cur = s.substr(i, len);

                    if (len < minLen) {
                        minLen = len;
                        ans = cur;
                    } 
                    else if (len == minLen && cur < ans) {
                        ans = cur;
                    }

                    // Adding more characters would only increase
                    // the length, so stop for this starting position.
                    break;
                }
            }
        }

        return ans;
    }
};