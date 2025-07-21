class Solution {
public:
      void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& board){
        int m=board.size();
        int n=board[0].size();
        vis[r][c]=1;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
         for(int i=0;i<4;i++){
              int newrow=r+dr[i];
              int newcol=c+dc[i];
              if(newrow>=0 && newrow<m &&newcol>=0 && newcol<n &&board[newrow][newcol]==1 && !vis[newrow][newcol]){
                  dfs(newrow,newcol,vis,board);
              }

         }
    }
    int numEnclaves(vector<vector<int>>& board) {
         int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //1 row amd last row
        for(int c=0;c<n;c++){
            if(board[0][c]==1){
                dfs(0,c,vis,board);
            }
        }
        for(int c=0;c<n;c++){
            if( board[m-1][c]==1){
                dfs(m-1,c,vis,board);
            }
        }
        for(int r=0;r<m;r++){
            if(board[r][0]==1){
                dfs(r,0,vis,board);
            }
        }
        for(int r=0;r<m;r++){
            if( board[r][n-1]==1){
                dfs(r,n-1,vis,board);
            }
        }
        int ans=0;
        for(int r=1;r<m;r++){
            for(int c=1;c<n;c++){
                if(board[r][c]==1 &&  !vis[r][c]){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};