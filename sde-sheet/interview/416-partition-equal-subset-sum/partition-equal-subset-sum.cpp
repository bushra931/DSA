class Solution {
public:
        bool istarget(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // base case
        if (target == 0) return true;
        if (ind == arr.size()) return false;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = istarget(ind + 1, target, arr, dp);

        bool take = false;
        if (arr[ind] <= target)
            take = istarget(ind + 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tsum = 0;
        for (int i = 0; i < n; i++) {
            tsum += nums[i];
        }

        // If total sum is odd, we can't partition it into two equal subsets
        if (tsum % 2 != 0) return false;

        int target = tsum / 2;
        vector<vector<int >> dp(n, vector<int>(target + 1, -1));
        return istarget(0, target, nums, dp);


    }
};
