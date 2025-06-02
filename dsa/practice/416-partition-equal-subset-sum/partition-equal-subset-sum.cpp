class Solution {
public:
    bool equate(int ind,int sum,int tsum,vector<int>& nums, vector<vector<int>>& dp){
        if(sum==(tsum-sum)) return true;
        if(ind==0){
            return sum==(tsum-sum);
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool nottaken=equate(ind-1,sum,tsum,nums,dp);
        bool taken=false;
        if(sum<=(tsum-sum)){
            taken=equate(ind-1,sum+nums[ind],tsum,nums,dp);
        }
        return dp[ind][sum]=nottaken||taken;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        for(int i=0;i<n;i++){
               tsum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(tsum,-1));
        return equate(n-1,0,tsum,nums,dp);  
   
    }
};