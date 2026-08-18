class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int n = nums.size();

        for(int i = 0; i <= n-k; i++) {
            unordered_set<int> s;
            for(int j = i; j < i+k; j++) s.insert(nums[j]);
            for(int x : s) cnt[x]++;
        }

        int ans = -1;
        for(auto [x,c] : cnt)
            if(c == 1) ans = max(ans, x);

        return ans;
    }
};