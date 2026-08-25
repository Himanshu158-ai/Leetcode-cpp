class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1; // 1 = down, -1 = up

        for (char ch : s) {
            rows[row] += ch;

            // Top par pahunch gaye -> neeche jaana
            if (row == 0) {
                direction = 1;
            }

            // Bottom par pahunch gaye -> upar jaana
            else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        string ans;

        for (string &r : rows) {
            ans += r;
        }

        return ans;
    }
};