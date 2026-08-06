class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n<=100){
            // int rem = 0;
            int val = 1;
            int x = n;
            while(x){
                int rem = x%10;
                x/=10;
                val*=rem;
            }
            if(val%t==0) return n;
            n++;
        }
        return -1;
    }
};