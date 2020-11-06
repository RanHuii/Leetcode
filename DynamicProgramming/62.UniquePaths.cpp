//
// Created by Harry Huang on 2020-11-05.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0;
        int dp[m][n];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int left = j -1;
                int top = i - 1;
                if(left >= 0 && top >= 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else if(left >= 0)
                    dp[i][j] = dp[i][j - 1];
                else if(top >= 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = 1;
            }
        }
        return dp[m - 1][n - 1];
        // TC: O(mn) m = height, n = width
        // SC: O(mn) m = height, n = width
    }
};