class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            string next = "";

            int count = 1;

            for (int j = 1; j < ans.length(); j++) {

                if (ans[j] == ans[j - 1]) {
                    count++;
                } 
                else {
                    next += to_string(count);
                    next += ans[j - 1];
                    count = 1;
                }
            }

            // Add the last group
            next += to_string(count);
            next += ans.back();

            ans = next;
        }

        return ans;
    }
};