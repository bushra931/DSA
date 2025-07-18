class Solution {
public:
    bool boundarychcek(int i,int j,vector<vector<int>>& grid){
        int m=grid.size(); //rows
        int n=grid[0].size();
        return (i>=0 && j>=0 && i<m && j<n);

    }
    int bfs_count(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int count=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=row+dr[k];
                int ncol=col+dc[k];
                if(boundarychcek(nrow,ncol,grid) && grid[nrow][ncol]==1 && vis[nrow][ncol]==-1){
                    count++;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }

            }
        }
        return count;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(); //rows
        int n=grid[0].size(); //coloumns
        vector<vector<int>> vis(m,vector<int>(n,-1));
        
        int maxarea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                     int area=bfs_count(i,j,grid,vis);
                     maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
        
    }
};