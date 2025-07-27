class Solution {
public:
    // int minsum(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    //     int n = matrix.size();
    //     if (dp[r][c] != -1) return dp[r][c];

    //     if (r == n - 1)
    //         return dp[r][c] = matrix[r][c]; 
    //     int down = minsum(r + 1, c, matrix, dp);
    //     int left = (c > 0)     ? minsum(r + 1, c - 1, matrix, dp) : INT_MAX;
    //     int right = (c < n - 1)? minsum(r + 1, c + 1, matrix, dp) : INT_MAX;

    //     return dp[r][c] = matrix[r][c] + min({down, left, right});
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int r=n-2;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                int down = dp[r + 1][c];
                int left = (c > 0) ? dp[r + 1][c - 1] : INT_MAX;
                int right = (c < n - 1)? dp[r + 1][c + 1]: INT_MAX;
                dp[r][c] = matrix[r][c] + min({down, left, right});
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
        
    }
};