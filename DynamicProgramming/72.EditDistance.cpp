class Solution {
public:
    int Recursive_minDistance(string word1, string word2) {
        int length1 = word1.length();
        int length2 = word2.length();
        
        // initialize a 2-D vector with length1 + 1 row and length2+1 column
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        
        //    "" a p p l e
        // "" 0  1 2 3 4 5
        // a
        // t
        // w
        //
        // first row empty string to string 2 by inserting
        // first column represent convert string1 to empty string 2 by deleting
        for(int i = 0; i < length1 + 1; i++)
        {
            for(int j = 0; j < length2 + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                {
                    dp[i][j] = i;
                }
               
            }
        }
        
        for(int i = 1; i < length1 + 1; i++)
        {
            for(int j = 1; j < length2 + 1; j++)
            {
                if(word1[i -1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[length1][length2];
    }
};