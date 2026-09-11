class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int>mapPattern;
        unordered_map<string,int>mapS;
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<pattern.size()){
            string str = "";
            while(j < s.size() && s[j] != ' '){
                str+=s[j];
                j++;
            }
            if(str == "") return false;
            if(mapPattern.find(pattern[i])==mapPattern.end()){
                mapPattern[pattern[i]] = i;
            }
            if(mapS.find(str)==mapS.end()){
                mapS[str] = k;
            }

            if(mapPattern[pattern[i]]!=mapS[str]) return false;
            i++,j++,k++;
        }
        if(j < s.size()) return false;
        return true;
    }
};