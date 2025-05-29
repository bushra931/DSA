class Solution {
public:
    int paths(int posr,int posc,int m, int n,vector<vector<int>>& dp){
        //base case
        if(posr==m-1 && posc==n-1){
            //finish
            return 1;
        }
        //edge
        if(posr>=m || posc>=n) return 0;
        //dp found
        if(dp[posr][posc]!=-1) return dp[posr][posc];
        //recursion 
        //posn se start move down
        return dp[posr][posc]=paths(posr+1,posc,m,n,dp)+paths(posr,posc+1,m,n,dp);
        //posn se right


    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
         return paths(0,0,m,n,dp);
  
    }
};