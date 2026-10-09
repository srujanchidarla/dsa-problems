#include <vector>
#include <algorithm>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — try every buy/sell pair.
public:
    int maxProfit(vector<int>& prices) {
        int best = 0;
        for (int buy = 0; buy < (int)prices.size(); buy++)
            for (int sell = buy + 1; sell < (int)prices.size(); sell++)
                best = max(best, prices[sell] - prices[buy]);
        return best;
    }
};

class Solution {
    // O(n) time | O(1) space — track cheapest day, best profit.
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, best = 0;
        for (int r = 1; r < (int)prices.size(); r++) {
            if (prices[r] > prices[l]) best = max(best, prices[r] - prices[l]);
            else l = r;
        }
        return best;
    }
};
