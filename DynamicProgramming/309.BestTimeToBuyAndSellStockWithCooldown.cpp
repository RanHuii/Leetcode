//
// Created by Harry Huang on 2020-11-08.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int n = prices.size();
        int dp[n][2];
        for(int i = 0; i < n; i++)
        {
            if(i -1 < 0)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
            }
            else if(i - 2 < 0)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], -prices[i]);
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }

        }
        return dp[n - 1][0];
    }

    int maxProfitWithConstantSpaceComplexity(vector<int>& prices)
    {
        if(prices.size() <= 1) return 0;
        int n = prices.size();
        int dp_i_no_stock = 0;
        int dp_i_own_stock = INT_MIN;
        int dp_pre_no_stock = 0;

        for(int i = 0; i < n; i++)
        {
            int temp = dp_i_no_stock;
            dp_i_no_stock = max(dp_i_no_stock, dp_i_own_stock + prices[i]);
            dp_i_own_stock = max(dp_i_own_stock, dp_pre_no_stock - prices[i]);

            dp_pre_no_stock = temp;
        }

        return dp_i_no_stock;
    }
};

