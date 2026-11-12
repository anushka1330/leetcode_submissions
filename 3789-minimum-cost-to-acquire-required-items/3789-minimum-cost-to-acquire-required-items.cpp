class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long both = min(need1, need2);
        return both * min(cost1 + cost2, costBoth)  // pair or bundle
             + (need1 - both) * min(cost1, costBoth)  // single or bundle
             + (need2 - both) * min(cost2, costBoth);
    }
};