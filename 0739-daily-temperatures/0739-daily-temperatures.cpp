class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>stk;
        vector<int>ans(temp.size());
        for(int i = temp.size()-1; i>=0; i--){
            while(!stk.empty() && stk.top().first<=temp[i]) stk.pop();
            ans[i] = stk.empty()? 0 : stk.top().second-i;
            stk.push({temp[i],i});
        }
        return ans;
    }
};