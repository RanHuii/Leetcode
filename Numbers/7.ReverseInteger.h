class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0)
        {
            int reminder = x % 10;
            result = result * 10 + reminder;
            
            x/= 10;
            
            if(result > INT_MAX || result < INT_MIN)
                return 0;
            
        }
        return result;
    }
    
    //TC:O(N) N = digits of the number
    //SC:O(1) 
};