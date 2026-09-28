class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        int c = 1;
        while(c!=n){
            int x = a+b;
            a = b;
            b = x;
            c++;
        }
        return a+b;
    }
};