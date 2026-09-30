class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";

        string ans = "";
        string hex = "0123456789abcdef";

        unsigned int n = num;

        while (n > 0) {
            int digit = n & 15;  // Get last 4 bits
            ans += hex[digit];
            n >>= 4;             // Remove last 4 bits
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};