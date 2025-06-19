class Solution {
public:
        void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>>& vis){
        vis[row][col]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<grid.size()&& ncol<grid[0].size() &&!vis[nrow][ncol] && grid[nrow][ncol]=='1' ){
                    vis[nrow][ncol]=1;
                    dfs(nrow,ncol,grid,vis);
                }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int islands=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    islands++;
                    dfs(row,col,grid,vis);
                }
            }
        }
        return islands;
        
    }
};