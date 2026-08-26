// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> temp(n);
//         stack<int> st;
//         int i = n-1;

//         while(i>=0){
//             while(!st.empty()){
//                 if(prices[i]>st.top()){
//                     st.pop();
//                 }else{
//                     temp[i] = st.top();
//                     st.pop();
//                     st.push(prices[i]);
//                     break;
//                 }
//             }
//             if(st.empty()){
//                 temp[i] = prices[i];
//                 st.push(prices[i]);
//             }
//             i--;
//         }

//         int ans = 0;
//         for(int j = 0; j<prices.size(); j++){
//             int val = temp[j]-prices[j];
//             ans+=val;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];
            }
        }

        return ans;
    }
};