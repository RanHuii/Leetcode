//
// Created by Harry Huang on 2020-11-06.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int buy = 0;
        int profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            int earn = prices[i] - prices[buy];
            if(earn < 0)
                buy = i;
            else
            {
                if(earn > profit)
                {
                    profit = earn;
                }
            }
        }
        return profit;
    }
};