class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find the sum of the longest sequential prefix.
        int sum = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Find the smallest missing integer >= sum.
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum)) {
            ++sum;
        }

        return sum;
    }
};