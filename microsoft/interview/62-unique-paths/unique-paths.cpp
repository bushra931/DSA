class Solution {
public:
    int count_ways(int r,int c,int m, int n,vector<vector<int>>& dp){
        if(r==m-1 && c==n-1) return 1;
        if(r>=m || c>=n) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        //
        int rightans=count_ways(r,c+1,m,n,dp);
        //down
        int downans=count_ways(r+1,c,m,n,dp);
        return dp[r][c]=rightans+downans;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return count_ways(0,0,m,n,dp);
        
    }
};