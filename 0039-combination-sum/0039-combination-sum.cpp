class Solution {
public:
    void helper(vector<int>& candidates, int target, int i,
                vector<int>& curr, vector<vector<int>>& ans) {

        // Base Case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (i == candidates.size() || target < 0)
            return;

        // ---------------- PICK ----------------
        curr.push_back(candidates[i]);

        // i same rahega kyunki same element ko fir se use kar sakte hain
        helper(candidates, target - candidates[i], i, curr, ans);

        curr.pop_back();

        // ---------------- NOT PICK ----------------
        // Ab current element ko permanently skip kar diya
        helper(candidates, target, i + 1, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, target, 0, curr, ans);

        return ans;
    }
};