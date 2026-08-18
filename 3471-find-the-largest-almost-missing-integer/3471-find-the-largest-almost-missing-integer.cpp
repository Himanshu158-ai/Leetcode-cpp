class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        int n = nums.size();

        // Har window ke liye
        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> st;

            // Current window ke unique elements
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Ye element ek window mein present hai
            for (auto x : st) {
                count[x]++;
            }
        }

        int ans = -1;

        for (auto it : count) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};