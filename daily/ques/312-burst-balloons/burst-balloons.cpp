class Solution {
public:
    // int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int maxi=INT_MIN;
    //     for(int ind=i;ind<=j;ind++){
    //         int cost=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
    //         maxi=max(maxi,cost);
    //     }
    //     return dp[i][j]=maxi;
    // }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=1;i<=n;i++){
            dp[i][i]=nums[i - 1] * nums[i] * nums[i + 1];
        }
        int len=2;
        while(len<=n){
            int i=1;
            int j=i+len-1;
            while(j<=n){
                int ii=INT_MIN;
                int k=i;
                while(k<=j){
                    int poss=nums[i-1]*nums[k]*nums[j+1];
                    if(k-1>=i) poss+=dp[i][k-1];
                    if (k+1<=j) poss+=dp[k+1][j];
                    ii=max(poss,ii);
                    k++;
                }
                dp[i][j]=ii;
                i++,j++;
            }

            len++;
        }
  
        return dp[1][n];
        
    }
};