class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1 && !s.count(n)) {
            s.insert(n);
            int x = 0;
            while (n) {
                x += (n % 10) * (n % 10);
                n /= 10;
            }
            n = x;
        }
        return n == 1;
    }
};