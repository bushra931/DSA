class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //bfs
        vector<vector<int>> vis(m,vector<int>(n,0));
        //{r,c,t}
        queue<pair<pair<int,int>,int>> q;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==2){ 
                    vis[r][c]=2;
                    q.push({{r,c},0});
                }
            }
        }
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            tm=max(tm,time);
            for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1 ){
                        vis[nrow][ncol]=2;
                        q.push({{nrow,ncol},time+1});
                    }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return tm;

        
    }
};