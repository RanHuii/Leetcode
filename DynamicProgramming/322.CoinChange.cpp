class Solution {
public:
    vector<int> count;
    int coinChange(vector<int>& coins, int amount) {
        count.resize(amount);
        return resursive(coins, amount);
    }
    
    int resursive(vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (count[amount - 1] != 0) return count[amount - 1];
        
        int min_step = INT_MAX;
        for(int coin: coins)
        {   
            int sub_problem = resursive(coins, amount - coin);
            if(sub_problem >= 0 && min_step > sub_problem)
                min_step = sub_problem + 1;
        }
        
        count[amount - 1] = (min_step == INT_MAX)? -1 : min_step;
        return count[amount - 1];
    }
    
    
    int iterative_coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] < 0)
                {
                    continue;
                }
                else
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return (dp[amount] == amount + 1)? -1 : dp[amount];
    }
};

// TC:O(coins * amount)
// SC:O(amount)