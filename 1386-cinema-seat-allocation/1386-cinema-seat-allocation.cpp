class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Mark reserved seats using a bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Every row without reservations can fit 2 groups
        int ans = (n - mp.size()) * 2;

        // Handle rows that contain reservations
        for (auto &[row, mask] : mp) {
            bool left = true;   // seats 2,3,4,5
            bool middle = true; // seats 4,5,6,7
            bool right = true;  // seats 6,7,8,9

            // Check left block: 2-5
            for (int seat = 2; seat <= 5; seat++) {
                if (mask & (1 << seat)) {
                    left = false;
                    break;
                }
            }

            // Check middle block: 4-7
            for (int seat = 4; seat <= 7; seat++) {
                if (mask & (1 << seat)) {
                    middle = false;
                    break;
                }
            }

            // Check right block: 6-9
            for (int seat = 6; seat <= 9; seat++) {
                if (mask & (1 << seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};