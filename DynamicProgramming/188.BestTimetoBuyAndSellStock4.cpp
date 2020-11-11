//
// Created by Harry Huang on 2020-11-11.
//
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1 || k <= 0)
            return 0;

        int n = prices.size();
        int dp[n][k + 1][2];

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                if( i - 1 < 0)
                {
                    dp[i][j][0] = 0;
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
        return dp[n - 1][k][0];
    }
};
// TC:O(n*k) n is size of stock k is k transaction
//