class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0)
            return 1.0 / myPow(x, -n);
        if (!n)
            return 1;
        double h = myPow(x, n / 2);
        return n % 2 ? h * h * x : h * h;
    }
};