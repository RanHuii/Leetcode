//
// Created by Harry Huang on 2020-11-11.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;

        int n = prices.size();
        int dp[n][3][2];

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <=2; j++)
            {
                if(i - 1 < 0)
                {
                    dp[i][j][0]  = 0;
                    dp[i][j][1] = -prices[i];
                }
                else
                {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                    if(j - 1 <= 0)
                        dp[i][j][1] = max(dp[i - 1][j][1],  -prices[i]);
                    else
                        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }

            }
        }
        return dp[n-1][2][0];
    }
};