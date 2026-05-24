class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            int onestep=dp[i-1];
            //2 step
            int twostep=dp[i-2];
            dp[i]=onestep+twostep;
        }
       
        return dp[n];
    }
};