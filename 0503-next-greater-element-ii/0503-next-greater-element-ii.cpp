class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>nxt;
        stack<int>prv;
        vector<int>nxtAns(nums.size());
        vector<int>prvAns(nums.size());
        for(int i = nums.size()-1; i>=0; i--){
            while(!nxt.empty() && nxt.top()<=nums[i]){
                nxt.pop();
            }
            nxtAns[i] = nxt.empty()? -1 : nxt.top();
            nxt.push(nums[i]);
        }

        for(int i = nums.size()-1; i>=0; i--){
            while(!nxt.empty() && nxt.top()<=nums[i]){
                nxt.pop();
            }
            prvAns[i] = nxt.empty()? -1 : nxt.top();
            nxt.push(nums[i]);
        }

        for(int i = 0; i<nxtAns.size(); i++){
            if(nxtAns[i]==-1 && prvAns[i]!=-1) nxtAns[i] = prvAns[i];
        }
        return nxtAns;
    }
};