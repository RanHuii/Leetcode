// 977 Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // check edge case
        if(nums.empty())
            return vector<int>();
        
        vector<int> res;
        int len = nums.size();
        // find the pivot of positive and negative number
        int negative = -1;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] < 0)
            {
                negative++;
            }
            else
            {
                break;
            }
        }
        int left = negative;
        int right = negative + 1;
        
        
        while(left >= 0 || right < len)
        {
            if(left >= 0 && right < len)
            {
                // compare the abs value
                if(abs(nums[left]) < abs(nums[right]))
                {
                    res.emplace_back(pow(nums[left],2));
                    left--;
                }
                else
                {
                    res.emplace_back(pow(nums[right],2));
                    right++;
                }
            }
            else if(left >= 0)
            {
                res.emplace_back(pow(nums[left],2));
                left--;
            }
            else if(right < len)
            {
                res.emplace_back(pow(nums[right],2));
                right++;
            }
        }
        return res;
    }
};