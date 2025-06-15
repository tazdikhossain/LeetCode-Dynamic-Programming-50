class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<int> dp(triangle[n - 1]);  

        for (int row = n - 2; row >= 0; --row) 
        {
            for (int i = 0; i <= row; ++i) 
            {
                dp[i] = triangle[row][i] + min(dp[i], dp[i + 1]);
            }
        }

        return dp[0];
    }
};
