class Solution {
public:

    void create(int n, vector<string>& ans, string& s, int open, int close){
        if(open==n && close==n){
            ans.push_back({s});
            return;
        }

        if(open<=n){
            s.push_back('(');
            create(n,ans,s,open+1,close);
            s.pop_back();
            // open--;
        }

        if(open>close && close<=n ){
            s.push_back(')');
            create(n,ans,s,open,close+1);
            s.pop_back();
            // close--;
        }
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        create(n,ans,s,0,0);
        return ans;
    }
};