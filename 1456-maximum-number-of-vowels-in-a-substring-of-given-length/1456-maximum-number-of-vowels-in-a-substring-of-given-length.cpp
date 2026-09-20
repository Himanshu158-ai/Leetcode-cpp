class Solution {
public:
    int maxVowels(string s, int k) {
        int vov = 0;
        int mx = 0;
        int i = 0, j = 0;
        while(j<k){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') vov++;
            j++;
        }
        mx = max(mx,vov);
        while(j<s.size()){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') vov--;
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') vov++;
            i++;
            j++;
            mx = max(mx,vov);
            if(vov==k) return k;
        }
        return mx;

    }
};