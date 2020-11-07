//
// Created by Harry Huang on 2020-11-07.
//

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int s1 = 1;
        int s2 = 2;
        int target;
        for(int i = 3; i <= n; i++)
        {
            target = s1 + s2;
            s1 = s2;
            s2 = target;
        }
        return target;
    }
};