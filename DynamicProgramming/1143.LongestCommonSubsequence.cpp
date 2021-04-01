class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.length();
        int length2 = text2.length();
        
        // dp[i][j] state: longest common subsequence length by comparing             // text1[0...i] and text2[0... j]
        // create dp table and handle base case
        
        // base case: when text1 is empty and text2 is empty
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        // traverse the dp table
        for(int i = 1; i < length1 + 1; i++)
        {
            for(int j = 1; j < length2 + 1; j++)
            {
                // condition1: current char under the index i j is the same
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // condition2: current char is different from text1 and text2
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[length1][length2];
    }
};