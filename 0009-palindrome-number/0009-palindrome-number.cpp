class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long r = 0, n = x;
        while (n)
            r = r * 10 + n % 10, n /= 10;
        return r == x;
    }
};