class Solution {
public:
    // int sump(vector<vector<int>>& matrix,int r,int c,vector<vector<int>> &dp){
    //     int n=matrix.size();
    //     if (c < 0 || c >= n) return INT_MAX;  
    //     if(r==n-1) return matrix[r][c];
    //     if(dp[r][c]!=-1) return dp[r][c];
    //     int down=matrix[r][c]+sump(matrix,r+1,c,dp);
    //     int dr = (c + 1 < n) ? matrix[r][c] + sump(matrix, r + 1, c + 1, dp) : INT_MAX;
    //     int dl = (c - 1 >= 0) ? matrix[r][c] + sump(matrix, r + 1, c - 1, dp) : INT_MAX;
    //     return dp[r][c]=min(down,min(dr,dl));
        
    // }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> front(n,0);
        for(int j=0;j<n;j++){
            front[j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=n-1;j>=0;j--){
                int d=front[j]+matrix[i][j];
                int dg=(j + 1 < n) ? front[j+1]+matrix[i][j] : INT_MAX;
                int dr=(j - 1 >= 0) ? front[j-1]+matrix[i][j]  : INT_MAX;
                curr[j]=min(d,min(dg,dr));
            }
            front=curr;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,front[i]);
        }
        return ans;
           
        
    }
};