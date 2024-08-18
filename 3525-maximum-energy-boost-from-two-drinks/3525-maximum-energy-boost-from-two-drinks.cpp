class Solution {
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));  // Use long long for dp

        // Initialize the first two elements
        dp[0][0] = a[0];
        dp[0][1] = b[0];

        if (n > 1) {
            dp[1][0] = a[0] + a[1];
            dp[1][1] = b[0] + b[1];
        }

        // Fill the dp table
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][0] + a[i], dp[i-2][1] + a[i]);
            dp[i][1] = max(dp[i-1][1] + b[i], dp[i-2][0] + b[i]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};
