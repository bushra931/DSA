class Solution {
public:
    int func(int r,int c,vector<vector<int>>& grid,int m,int n,vector<vector<int>> &dp){
        if(r==m-1 && c==n-1) return grid[r][c];
        if(r>=m || c>=n) return 1e9;
        if(dp[r][c]!=-1) return dp[r][c];
        int right=grid[r][c]+func(r,c+1,grid,m,n,dp);
        int down=grid[r][c]+func(r+1,c,grid,m,n,dp);
        return dp[r][c]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,grid,m,n,dp);


    }
};