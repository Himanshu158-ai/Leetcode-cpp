class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i = 0;
        int j = nums.size()-1;
        int count = nums.size();
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
                count--;
            }else i++;
        }
        return count;
    }
};