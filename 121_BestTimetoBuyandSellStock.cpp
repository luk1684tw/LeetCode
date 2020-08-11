#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = 1000000;
        for (int i = 0; i < prices.size(); i++) {
            if (min_price > prices[i]) min_price = prices[i];
            else if (prices[i] - min_price > ans) ans = prices[i] - min_price;
        }

        return ans;
    }
};