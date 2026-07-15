class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size(),n=grid[0].size();
        vector<int> dp(n,0);
         int maxans=1;
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                int good=1;
                for(int l=0;l<m;l++){
                     if(abs(grid[l][j]-grid[l][i])>limit) {
                        good=0;
                        break;
                     }
                }
                if(good==1) dp[i]=max(dp[i],dp[j]+1);

            }
             maxans=max(maxans,dp[i]);
        }
        return maxans;

        
    }
};