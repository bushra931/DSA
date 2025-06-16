class Solution {
public:
    int coins_cnt(int ind,vector<int>& coins, int amount, vector<vector<int>>& dp){
        //base case
        if(ind==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        //not take
        int nottake=0+coins_cnt(ind-1,coins,amount,dp);
        //take
        int take=INT_MAX;
        if(coins[ind]<=amount){
            take=1+coins_cnt(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(nottake,take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=coins_cnt(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;

    }
};