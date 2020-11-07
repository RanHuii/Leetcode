//
// Created by Harry Huang on 2020-11-06.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int buy = 0;
        int max_profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            int earn = prices[i] - prices[buy];
            buy = earn < 0? i : buy;
            max_profit = max(max_profit, earn);

        }
        return max_profit;
    }

    int maxProfit_method2(vector<int>& prices)
    {
        if(prices.size() <= 1)
            return 0;
        int min_price = prices[0];
        int max_profit = 0;

        for(int i = 1, cur; i < prices.size(); i++)
        {
            cur = prices[i];
            min_price = min(min_price, cur);
            max_profit = max(max_profit, cur - min_price);
        }

        return max_profit;
    }

};