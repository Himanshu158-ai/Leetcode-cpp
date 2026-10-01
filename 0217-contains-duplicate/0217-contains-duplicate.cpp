class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mapi;
        for(int i = 0; i<nums.size(); i++){
            if(mapi.find(nums[i])!=mapi.end()) return true;
            mapi[nums[i]]++;
        }
        return false;
    }
};