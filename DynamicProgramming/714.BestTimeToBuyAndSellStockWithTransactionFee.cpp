//
// Created by Harry Huang on 2020-11-15.
//

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1)
            return 0;
        int no_stock = 0;
        int hold_stock = INT_MIN;

        for(int i = 0; i < prices.size(); i++)
        {
            no_stock = max(no_stock, hold_stock + prices[i]);
            hold_stock = max(hold_stock, no_stock - prices[i]  - fee);
        }

        return no_stock;
    }
};

// TC: O(N)
// SC: O(1)