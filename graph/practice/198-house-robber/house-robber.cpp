class Solution {
private:
    int solve(int ind,vector<int>& arr,vector<int> &dp){
        if (ind < 0) return 0;
        if (ind == 0) return arr[ind];
        if (dp[ind] != -1) return dp[ind];
    
        int pick = arr[ind] + solve(ind - 2, arr, dp);
        int nonpick = solve(ind - 1, arr, dp);
        return dp[ind] = max(pick, nonpick);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);   
    }
};