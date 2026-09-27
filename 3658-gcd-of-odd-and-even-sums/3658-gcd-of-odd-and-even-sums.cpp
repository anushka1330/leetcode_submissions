class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 1LL * n * n;
        long long sumEven = 1LL * n * (n + 1);

        return std::gcd(sumOdd, sumEven);
    }
};