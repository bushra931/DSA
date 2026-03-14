class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,int m,int n){
        vis[row][col]=1;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
                int nr=row+drow[k];
                int nc=col+dcol[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]=='1' && !vis[nr][nc] ){
                    dfs(nr,nc,grid,vis,m,n);
                }
         }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,vis,m,n);
                }
            }
        }
        return cnt;
    }
};