class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        int count = 0;
        while(i<=j){
            int sum = people[i]+people[j];
            if(sum<=limit){
                count++;
                i++,j--;
            }else{
                if(people[i]>people[j]){
                    i++;
                    count++;
                }else{
                    j--;
                    count++;
                }
            }
        }
        return count;
    }
};