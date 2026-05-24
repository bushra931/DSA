class Solution {
public: 
    int maxprofit(int ind,vector<int>& dp,vector<int>& nums){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        //choose
        int choose=nums[ind]+maxprofit(ind-2,dp,nums);
        //not
        int notchoose=0+maxprofit(ind-1,dp,nums);
        return dp[ind]=max(choose,notchoose);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return maxprofit(n-1,dp,nums);
    }
};