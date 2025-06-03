class Solution {
public:
    int uniquePaths(int m, int n) {
        
        long long result = 1;
        int k = m - 1; 
        int total = m + n - 2;

        for (int i = 1; i <= k; ++i) 
        {
            result = result * (total - k + i) / i;
        }

        return (int)result;
    }
};
