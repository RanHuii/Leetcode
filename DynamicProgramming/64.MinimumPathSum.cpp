class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int width = grid[0].size();
        int height = grid.size();
        int dp[height][width];
        
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                int left = j - 1;
                int top = i - 1;
                if(left >= 0 && top >= 0)
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                else if(left >= 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if(top >= 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[height - 1][width - 1];
    }
};