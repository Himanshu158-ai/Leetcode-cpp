class Solution {
public:

    void comb(vector<string> &mp, string &digits, vector<string> &ans, string &store, int i){
        if(i==digits.size()){
            ans.push_back(store);
            return;
        }

        // int n = mp[digits[i]-'0'].length();
        string val = mp[digits[i]-'0'];
        for(int j = 0; j<val.length(); j++){
            store+=val[j];
            comb(mp,digits,ans,store,i+1);
            store.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mp = {
            "...",
            "...",
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        vector<string>ans;
        string store="";
        comb(mp,digits,ans,store,0);
        return ans;
    }
};