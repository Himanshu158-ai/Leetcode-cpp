class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suffix[j] = smallest index in word1 from which
        // word2[j...] can be formed as an exact subsequence.
        vector<int> suffix(m + 1);

        suffix[m] = n;

        int i = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (i >= 0 && word1[i] != word2[j]) {
                i--;
            }

            if (i < 0) {
                suffix[j] = -1;
            } else {
                suffix[j] = i;
                i--;
            }
        }

        vector<int> ans;

        i = 0;
        bool mismatchUsed = false;

        for (int j = 0; j < m; j++) {

            // Find lexicographically smallest possible index
            while (i < n) {

                // Exact match
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    break;
                }

                // Try using our one allowed mismatch
                if (!mismatchUsed) {

                    // If this is the last character,
                    // mismatch can always be used.
                    if (j == m - 1) {
                        ans.push_back(i);
                        mismatchUsed = true;
                        i++;
                        break;
                    }

                    // After choosing i as mismatch,
                    // remaining word2[j+1...] must be formable
                    // using indices > i.
                    if (suffix[j + 1] != -1 &&
                        i < suffix[j + 1]) {

                        ans.push_back(i);
                        mismatchUsed = true;
                        i++;
                        break;
                    }
                }

                i++;
            }

            // Could not select an index for word2[j]
            if (ans.size() != j + 1) {
                return {};
            }
        }

        return ans;
    }
};