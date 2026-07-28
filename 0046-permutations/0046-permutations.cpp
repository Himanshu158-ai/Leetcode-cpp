// class Solution {
// public:

//     void permut(vector<int>& nums, unordered_map<int,int>& mapi,vector<int>& store,vector<vector<int>>& ans){
//         if(store.size()==nums.size()){
//             ans.push_back(store);
//             return;
//         }

//         for(int i = 0; i<nums.size(); i++){
//             if(mapi.find(nums[i])==mapi.end()){
//                 mapi[nums[i]]++;
//                 store.push_back(nums[i]);
//                 permut(nums,mapi,store,ans);
//                 store.pop_back();
//                 mapi.erase(nums[i]);
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         unordered_map<int,int>mapi;
//         vector<int>store;
//         vector<vector<int>>ans;
//         permut(nums,mapi,store,ans);
//         return ans;
//     }
// };







//optimize
class Solution {
public:

    void permut(vector<int>& nums,vector<vector<int>>& ans,int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j<nums.size(); j++){
            swap(nums[i],nums[j]);
            permut(nums,ans,i+1);

            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permut(nums,ans,0);
        return ans;
    }
};