class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& mat,vector<vector<int>>& vis){
        vis[row][col]=1;
        int m=mat.size();
        int n=mat[0].size();
        //neighbours 
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol]&& mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,mat,vis);
            } 
        }
    }


public:
    void solve(vector<vector<char>>& mat) {
        //logic-> boundary o dfs travers krege kyuki unse connected o ka koi us side ka x nhi to to woh bhi o x nhi bn skte

        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //row top and bottom 
        for(int j=0;j<n;j++){
            //top
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,mat,vis);
            }
            //bottom 
            if(!vis[m-1][j] && mat[m-1][j]=='O'){
                dfs(m-1,j,mat,vis);
            }

        }
       for(int i=0;i<m;i++){  // Fix here
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,mat,vis);
            }
            if(!vis[i][n-1] && mat[i][n-1]=='O'){
                dfs(i,n-1,mat,vis);
            }
        }
        // now boundary connected zero marked vis now left zero can be converted
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='O' && !vis[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        return;


        
    }
};