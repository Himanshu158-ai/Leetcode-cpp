class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0, lst = height.size()-1;
        int mx = 0;
        while(st<lst){
            mx = max((min(height[st],height[lst])*(lst-st)),mx);

            if(height[st]<height[lst]){
                st++;
            }else lst--;
        }
        return mx;
    }
};