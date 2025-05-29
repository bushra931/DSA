class Solution {
public:
    // int paths(int posr,int posc,int m, int n,vector<vector<int>>& dp){
    //     //base case
    //     if(posr==m-1 && posc==n-1){
    //         //finish
    //         return 1;
    //     }
    //     //edge
    //     if(posr>=m || posc>=n) return 0;
    //     //dp found
    //     if(dp[posr][posc]!=-1) return dp[posr][posc];
    //     //recursion 
    //     //posn se start move down
    //     return dp[posr][posc]=paths(posr+1,posc,m,n,dp)+paths(posr,posc+1,m,n,dp);
    //     //posn se right


    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){ 
            //table
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){ 
            //table
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
};