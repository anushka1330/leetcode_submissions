class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, ans = 0;

        for (int x : nums) {
            if (x == 1) {
                curr++;
                ans = max(ans, curr);
            } else {
                curr = 0;
            }
        }

        return ans;
    }
};