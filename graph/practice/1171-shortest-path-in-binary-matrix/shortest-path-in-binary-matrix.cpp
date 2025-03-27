class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       queue<pair<int, pair<int, int>>> q;
        int n=grid.size();
        //missed this edge case
         if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
       while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            // for one element [0] its aslso handle it
            if(r==n-1 &&c==n-1 && grid[r][c]==0) return dis;
            for(int drow=-1;drow<=1;drow++){
               for(int dcol=-1;dcol<=1;dcol++){
                 int nrow=r+drow;
                 int ncol=c+dcol;
                 if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol] ){
                    q.push({dis+1,{nrow,ncol}});
                    dist[nrow][ncol]=dis+1;
                 }

            }
        }

       }
       return -1;
        
    }
};