class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int leftQ = 0;
        int rightQ = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                diff += num[i] - '0';
            }
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                diff -= num[i] - '0';
            }
        }

        // Bob can only force equality if the total number
        // of '?' is even.
        if ((leftQ + rightQ) % 2 != 0)
            return true;

        // Bob wins if the fixed difference can be exactly
        // compensated by the question marks.
        int required = 9 * (rightQ - leftQ) / 2;

        return diff != required;
    }
};