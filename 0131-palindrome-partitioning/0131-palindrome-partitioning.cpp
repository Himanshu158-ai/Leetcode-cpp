class Solution {
public:

    bool isPal(string par){
        string rev = par;
        reverse(par.begin(), par.end());
        return rev==par?true:false;
    }

    void helper(string s, vector<vector<string>>& ans, vector<string>& part){
        if(s.size()==0){
            ans.push_back(part);
            return;
        }


        for(int j = 0; j<s.size(); j++){
            string par = s.substr(0,j+1);
            if(isPal(par)){
                part.push_back(par);
                helper(s.substr(j+1),ans,part);
                part.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        helper(s,ans,part);
        return ans;
    }
};