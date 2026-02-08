class Solution {
public:
    void dfsvis(int r,int c,vector<vector<char>>& board,vector<vector<int>> & vis){
        int m=board.size();
        int n=board[0].size();
        vis[r][c]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<=m-1 && ncol>=0 && ncol<=n-1 && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfsvis(nrow,ncol,board,vis);
            }
        }
    }
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>> & vis){
        int m=board.size();
        int n=board[0].size();
        board[r][c]='X';
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<=m-1 && ncol>=0 && ncol<=n-1 && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        //dfs in internal
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //first row
        for(int c=0;c<n;c++){
            if(board[0][c]=='O') dfsvis(0,c,board,vis);
        }
        //last row
        for(int c=0;c<n;c++){
            if(board[m-1][c]=='O') dfsvis(m-1,c,board,vis);
        }
        //first col 
        for(int c=0;c<m;c++){
            if(board[c][0]=='O') dfsvis(c,0,board,vis);
        }
        //last col
        for(int c=0;c<m;c++){
            if(board[c][n-1]=='O') dfsvis(c,n-1,board,vis);
        }

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j]=='O' && !vis[i][j]) dfs(i,j,board,vis);
            }
        }
        return;
        
    }
};