//
// Created by Harry Huang on 2020-11-18.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];

        int dp_prev = nums[0];
        int dp_cur = max( 0 + nums[1], dp_prev);
        for(int i = 2; i < nums.size(); i++)
        {
            int temp = dp_cur;
            dp_cur = max(dp_prev + nums[i], dp_cur);
            dp_prev = temp;
        }

        return dp_cur;
    }

    // TC:O(n)
    // SC:O(1)
};