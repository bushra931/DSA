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
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // vector<int> prev(m,1);
        // vetor<int> curr(n,1);
        // for(int j=1;j<m;j++){
        //     for(int i=1;i<n;i++){
        //         prev[i]=prev[i-1]+curr[i];      
        // }
        // }
        
        // return dp[m-1][n-1];
        //space optimised
        vector<int> prev(n,1);
        for(int i=1;i<m;i++){
            vector<int> curr(n,1);
            for(int j=1;j<n;j++){
                curr[j]=curr[j-1]+prev[j];
                //[1, 2, 3]  ← comes from: [1, 1+1, 2+1]

            }
            prev=curr;

        }
        return prev[n-1];

    }
};