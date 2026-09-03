class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasOdd = false;
        
        for (int x : nums1) {
            if (x % 2 == 1) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }
        
        // All numbers are even already.
        if (!hasOdd) return true;
        
        // Every even number must have a smaller odd number.
        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd) {
                return false;
            }
        }
        
        return true;
    }
};