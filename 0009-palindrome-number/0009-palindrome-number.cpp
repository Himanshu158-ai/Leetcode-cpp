class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int old_val = x;
        int new_val = 0;

        while(x>0){
            int rem = x%10;
            
             if(new_val > INT_MAX / 10 ||
                (new_val == INT_MAX / 10 && rem > INT_MAX % 10)){
                return false;
            }

            new_val = new_val*10+rem;
            x/=10;
        }

        if(old_val==new_val) return true;
        return false;
    }
};