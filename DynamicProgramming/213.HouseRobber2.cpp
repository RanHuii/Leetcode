//
// Created by Harry Huang on 2020-11-19.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int num1, num2;
        int dp_i, dp_j;
        dp_i = 0;
        dp_j = nums[1];
        for(int i = 2; i < nums.size(); i++)
        {
            int temp = dp_j;
            dp_j = max(dp_i + nums[i], dp_j);
            dp_i = temp;
        }
        num1 = dp_j;

        dp_i = 0;
        dp_j = nums[0];
        for(int i = 1; i < nums.size() -1; i++)
        {
            int temp = dp_j;
            dp_j = max(dp_i + nums[i], dp_j);
            dp_i = temp;
        }

        return max(num1, dp_j);
    }

};