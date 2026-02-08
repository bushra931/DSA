class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis=image;
        if(image[sr][sc]==color) return vis;
        //{r,c,colour}
        queue<pair<pair<int,int>,int>> q;
        q.push({{sr,sc},color});
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int color=q.front().second;
            q.pop();
            vis[r][c]=color;
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==image[r][c] && vis[nrow][ncol]!=color){
                    q.push({{nrow,ncol},color});
                }
            }
        }
        return vis;

        
    }
};