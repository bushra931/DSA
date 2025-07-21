class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int m=image.size();
            int n=image[0].size();
            int startcolor=image[sr][sc];
            image[sr][sc]=color;
            queue<pair<int,int>> q;
            vector<vector<int>> vis(m,vector<int>(n,0));
            q.push({sr,sc});
            while(!q.empty()){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                int dr[4]={-1,0,1,0};
                int dc[4]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int newrow=r+dr[i];
                    int newcol=c+dc[i];
                    if(newrow>=0 && newrow<m &&newcol>=0 && newcol<n && image[newrow][newcol]==startcolor && vis[newrow][newcol]!=1){
                        vis[newrow][newcol]=1;
                        image[newrow][newcol]=color;
                        q.push({newrow,newcol});
                    }
                }
            }
            return image;


        
    }
};