class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        // Inclusion-exclusion
        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    L = lcm(L, (long long)coins[i]);

                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            if (bits % 2)
                total += x / L;
            else
                total -= x / L;
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid, coins) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};