class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mapi;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mapi[nums[i]]++;
        }

        for(auto& m:mapi){
            if(m.second>n/2) return m.first;
        }
        return -1;

    }
};