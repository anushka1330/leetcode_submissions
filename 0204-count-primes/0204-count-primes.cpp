class Solution {
public:
    int countPrimes(int n) {
        vector<bool> p(n, true);
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (p[i]) {
                ans++;
                if (1LL * i * i < n)
                    for (int j = i * i; j < n; j += i)
                        p[j] = false;
            }
        return ans;
    }
};