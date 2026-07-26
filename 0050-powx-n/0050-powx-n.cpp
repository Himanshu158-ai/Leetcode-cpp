class Solution {
public:
    double mul(double x, long long n){
        if(n<=1) return x;

        double val = mul(x,n/2);
        return n%2!=0 ? val*val*x: val*val;
    }


    double myPow(double x, int n) {
        if(n==0) return 1.00000;
        
        long long newVal = (long long)n;
        long long absN = abs(newVal);
        double ans = mul(x,absN);
        return n<0?1.00000/ans:ans;
    }
};