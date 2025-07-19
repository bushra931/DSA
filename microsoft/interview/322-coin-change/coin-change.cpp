class Solution {
public:
    int mincoins(int i,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(i==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return INT_MAX;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];
        //not take
        int nottake=0+mincoins(i-1,coins,amount,dp);
        //take
        int take=INT_MAX;
        if(amount>=coins[i]){
            int sub=mincoins(i,coins,amount-coins[i],dp);
            if(sub < INT_MAX) take = 1 + sub;
        }
        return dp[i][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        if(amount==0) return 0;
        int ans=mincoins(coins.size()-1,coins,amount,dp);
        if(ans>=INT_MAX) return -1;
        return ans;


        
    }
};