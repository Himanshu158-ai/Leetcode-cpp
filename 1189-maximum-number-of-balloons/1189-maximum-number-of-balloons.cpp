class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>need;
        unordered_map<char,int>have;
        string st = "balloon";
        int mn = INT_MAX;

        for(int i = 0; i<st.length(); i++){
            need[st[i]]++;
        }
        for(int i = 0; i<text.length(); i++){
            have[text[i]]++;
        }

        for(auto nd:need){
            char val = nd.first;
            int freq = nd.second;

            int x = have[val]/freq;
            mn = min(mn,x);
        }

    return mn;
    }
};