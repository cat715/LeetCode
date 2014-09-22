class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        int result = 1;
        for(int i = 2; i <= n; i++) {
            result = a + b;
            a = b; 
            b = result;
        }
        return result;
    }
};