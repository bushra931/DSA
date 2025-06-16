class Solution {
public:
    // int lcs(int i,int j,string text1, string text2,vector<vector<int>>& dp){
    //     //base case
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     //match
    //     if(text1[i]==text2[j]){
    //         return dp[i][j]=1+lcs(i-1,j-1,text1,text2,dp);
    //     }
    //     //unmatch
    //     else{
    //         return dp[i][j]=0+max(lcs(i-1,j,text1,text2,dp),lcs(i,j-1,text1,text2,dp));
    //     }
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //match
                if(text1[i-1]==text2[j-1]){ // neccessary i-1 as yeh yha index isliye warna 0th index se match nhi hoga balhi dp ke liye alg h yeh baat
                    dp[i][j]=1+dp[i-1][j-1];
                }
                //unmatch
                else{
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
          
    }
};