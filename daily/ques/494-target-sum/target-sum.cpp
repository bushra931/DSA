#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int solve(int idx, int currSum, vector<int>& nums, int target,
              vector<unordered_map<int, int>>& dp) {

        if (idx == nums.size()) {
            return currSum == target;
        }

        if (dp[idx].count(currSum)) {
            return dp[idx][currSum];
        }

        int add = solve(idx + 1, currSum + nums[idx], nums, target, dp);
        int sub = solve(idx + 1, currSum - nums[idx], nums, target, dp);

        return dp[idx][currSum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);

        return solve(0, 0, nums, target, dp);
    }
};