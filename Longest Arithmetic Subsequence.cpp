#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        // dp[i][diff] = length of sequence ending at i with difference diff
        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                // If there's a sequence ending at j with this diff, extend it
                int len = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                dp[i][diff] = max(dp[i][diff], len);
                maxLen = max(maxLen, dp[i][diff]);
            }
        }

        return maxLen;
    }
};
