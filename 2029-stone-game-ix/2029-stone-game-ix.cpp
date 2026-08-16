class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones)
            cnt[x % 3]++;

        // If there are no non-zero remainder stones,
        // Alice cannot make a winning move.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // Known condition for Stone Game IX.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};