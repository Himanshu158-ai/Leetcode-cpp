class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> temp(n);
        stack<int> st;
        int i = n-1;

        while(i>=0){
            while(!st.empty()){
                if(prices[i]>st.top()){
                    st.pop();
                }else{
                    temp[i] = st.top();
                    st.pop();
                    st.push(prices[i]);
                    break;
                }
            }
            if(st.empty()){
                temp[i] = prices[i];
                st.push(prices[i]);
            }
            i--;
        }

        int ans = 0;
        for(int j = 0; j<prices.size(); j++){
            int val = temp[j]-prices[j];
            ans+=val;
        }
        return ans;
    }
};