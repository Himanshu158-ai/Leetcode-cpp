class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i = 0,j=skill.size()-1;
        long long exp = skill[i]+skill[j];
        long long ans = 0;
        while(i<j){
            long long sum = skill[i]+skill[j];
            if(sum==exp){
                ans = (skill[i]*skill[j])+ans;
                i++,j--;
            }else return -1;
        }
        return ans;
    }
};