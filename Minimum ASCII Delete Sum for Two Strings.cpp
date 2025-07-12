class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases: delete all characters from s1 or s2
        for (int i = m - 1; i >= 0; --i)
            dp[i][n] = dp[i + 1][n] + s1[i];

        for (int j = n - 1; j >= 0; --j)
            dp[m][j] = dp[m][j + 1] + s2[j];

        // Bottom-up DP
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1]; // characters match, no cost
                } else {
                    dp[i][j] = min(
                        s1[i] + dp[i + 1][j],  // delete from s1
                        s2[j] + dp[i][j + 1]   // delete from s2
                    );
                }
            }
        }

        return dp[0][0]; // result for s1 and s2
    }
};
