class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prv_day = prices[0];
        int ans = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]<prv_day){
                prv_day = prices[i];
            }else{
                int temp = prices[i]-prv_day;
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};