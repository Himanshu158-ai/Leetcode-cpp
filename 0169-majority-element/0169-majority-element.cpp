class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current_val = nums[0];
        int count = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]==current_val){
                count++;
            }else{
                count--;
                if(count==0) {
                    current_val = nums[i];
                    count++;
                };
            }
        }
        return current_val;

    }
};