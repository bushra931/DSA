class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //rotten -> pop ->adj rotten put in quuee->t++
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
         int tm=0;

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++){
                    int newrow=r+dr[i];
                    int newcol=c+dc[i];
                    if(newrow>=0 && newrow<m &&newcol>=0 && newcol<n && grid[newrow][newcol]==1 && vis[newrow][newcol]!=1){
                        vis[newrow][newcol]=1;
                        q.push({{newrow,newcol},t+1});
                    }
        }


        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return tm;
    }
};