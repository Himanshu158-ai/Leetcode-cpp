class Solution {
public:
    void helper(vector<int>& candidates, int target, set<vector<vector<int>>>& s, int i, vector<int>values, vector<vector<int>>& ans){
        if(i>=candidates.size() || target<0){
            return;
        }
        if(target==0){
            if(s.find({values})==s.end()){
                s.insert({values});
                ans.push_back(values);
            }
            return;
        }

        values.push_back(candidates[i]);
        helper(candidates,target-candidates[i],s,i+1,values,ans);
        helper(candidates,target-candidates[i],s,i,values,ans);
        values.pop_back();
        helper(candidates,target,s,i+1,values,ans);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<vector<int>>>s;
        vector<vector<int>>ans;
        vector<int>values;
        helper(candidates,target,s,0,values,ans);



        return ans;
    }
};