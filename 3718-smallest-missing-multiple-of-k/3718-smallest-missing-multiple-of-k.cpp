class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        for (int multiple = k; ; multiple += k) {
            if (s.find(multiple) == s.end()) {
                return multiple;
            }
        }
    }
};