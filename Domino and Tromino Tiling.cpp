#include <vector>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1'000'000'007;
        vector<long long> dp(n + 1, 0);
        
 
        dp[0] = 1; 
        if (n >= 1) dp[1] = 1; 
        if (n >= 2) dp[2] = 2; 
        
       
        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2] + 2LL * dp[i-3]) % MOD;
        }
        
        return dp[n];
    }
};
