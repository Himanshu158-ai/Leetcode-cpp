class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size()-1;
        int i = nums.size()-2;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                while(j>i){
                    if(nums[j]>nums[i]){
                        swap(nums[i],nums[j]);
                        reverse(nums.begin()+i+1,nums.end());
                        break;
                    }else j--;
                }
                break;
            }else i--;
        }

        if(i<0) {
            reverse(nums.begin(),nums.end());
        }
    }
};