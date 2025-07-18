#include <vector>
#include <algorithm>

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        // Step 1: Sort envelopes
        std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // Descending height if width same
            return a[0] < b[0]; // Ascending width
        });

        // Step 2: Extract the heights
        std::vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        // Step 3: Find LIS on heights
        std::vector<int> dp; // dp[i] stores the smallest tail of all increasing subsequences with length i+1
        for (int h : heights) {
            auto it = std::lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) {
                dp.push_back(h);
            } else {
                *it = h;
            }
        }

        return dp.size();
    }
};
