class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > tsum) return 0; // early pruning
        int offset = tsum;
        int maxRange = 2 * tsum + 1;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(maxRange, 0));

        // Base case: sum = 0 with 0 elements
        dp[0][offset] = 1;

        for (int ind = 0; ind < n; ind++) {
            for (int sum = -tsum; sum <= tsum; sum++) {
                if (dp[ind][sum + offset] > 0) {
                    // + nums[ind]
                    dp[ind + 1][sum + nums[ind] + offset] += dp[ind][sum + offset];
                    // - nums[ind]
                    dp[ind + 1][sum - nums[ind] + offset] += dp[ind][sum + offset];
                }
            }
        }

        if (target + offset < 0 || target + offset >= maxRange) return 0;
        return dp[n][target + offset];
    }
};
