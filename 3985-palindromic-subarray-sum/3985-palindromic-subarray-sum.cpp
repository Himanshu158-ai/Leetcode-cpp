class Solution {
public:
    long long getSum(vector<int>& nums) {
        vector<int> nalviretho = nums;

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        auto getSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        long long ans = 0;

        for (int x : nums)
            ans = max(ans, 1LL * x);

        vector<int> d1(n);
        int l = 0, r = -1;

        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n && nums[i - k] == nums[i + k])
                k++;

            d1[i] = k;

            int left = i - k + 1;
            int right = i + k - 1;
            ans = max(ans, getSum(left, right));

            if (right > r) {
                l = left;
                r = right;
            }
        }
        vector<int> d2(n);
        l = 0;
        r = -1;

        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

            while (i - k - 1 >= 0 && i + k < n &&
                   nums[i - k - 1] == nums[i + k])
                k++;

            d2[i] = k;

            if (k > 0) {
                int left = i - k;
                int right = i + k - 1;
                ans = max(ans, getSum(left, right));
            }

            int newLeft = i - k;
            int newRight = i + k - 1;

            if (newRight > r) {
                l = newLeft;
                r = newRight;
            }
        }

        return ans;
    }
};