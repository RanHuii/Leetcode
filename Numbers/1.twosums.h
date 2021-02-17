class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int subtract = 0;
        for(size_t i = 0; i < nums.size(); i++)
        {
            subtract = target - nums[i];
            if(map.find(subtract) != map.end())
            {
                return vector<int>{map[subtract], (int)i};
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};