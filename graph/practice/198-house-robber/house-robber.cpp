class Solution {
private:
    int solve(int n,vector<int>& arr,vector<int> &dp){
       if (n == 0) return 0;
    if (n == 1) return arr[0];

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int pick = arr[i] + dp[i - 2];
        int nonpick = dp[i - 1];
        dp[i] = max(pick, nonpick);
    }

    return dp[n - 1];
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n,nums,dp);   
    }
};