class Solution {
public:
    int reverse(int x) {
        vector<int> nums;
        while(x != 0)
        {
            nums.push_back(x%10);
            x/=10;
        }
        int len = nums.size();
        long long result = 0;
        for(int i = 0, exp = len - 1; i < len; i++, exp--)
        {
            if(result + nums[i]*pow(10,exp) > INT_MAX || result - nums[i]*pow(10,exp) < INT_MIN)
                return 0;
                
            result += nums[i]*pow(10,exp);
        }
        return result;
    }
    
    //TC:O(N) N = digits of the number
    //SC:O(N) N = digits of the number
};