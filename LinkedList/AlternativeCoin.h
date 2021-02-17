// There are N coins, each showing either heads or tails. We would like all the coins
// to form a sequence of alternating heads and tails. 
// What is the minimum of coins that must be reversed to achieve this?
#include <vector>
class Solution
{
    int solution(std::vector<int> &A)
    {
        if(A.empty())
            return 0;
        
        int dp_i_0, dp_i_1;

        if(A[0] == 0)
        {
            dp_i_0 = 0;
            dp_i_1 = 1;
        }
        else
        {
            dp_i_0 = 1;
            dp_i_1 = 0;
        }

        for(unsigned int i = 1; i < A.size(); i++)
        {
            int prev_0 = dp_i_0;
            if(A[i] == 1)
            {
                dp_i_0 = 1 + dp_i_1;
                dp_i_1 = prev_0;
            }
            else
            {
                dp_i_0 = dp_i_1;
                dp_i_1 = 1 + prev_0;
            }
            
        }

        return std::min(dp_i_0, dp_i_1);
    }

};