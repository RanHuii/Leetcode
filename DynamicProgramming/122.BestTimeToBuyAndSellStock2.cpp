//
// Created by Harry Huang on 2020-11-11.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;

        for(int i = 0; i < prices.size(); i++)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};

