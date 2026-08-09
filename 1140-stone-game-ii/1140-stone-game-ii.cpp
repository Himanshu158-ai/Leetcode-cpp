class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int total = suffix[i];

        int ans = 0;

        // Take X piles, where 1 <= X <= 2*M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            // Alice takes X piles.
            // Bob will then play optimally and get solve(i+X, max(M,X)).
            // So Alice's stones = total remaining - Bob's maximum.
            int bob = solve(i + X, max(M, X));

            ans = max(ans, total - bob);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        dp.assign(n, vector<int>(n + 1, -1));

        // suffix[i] = sum of piles from i to n-1
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return solve(0, 1);
    }
};