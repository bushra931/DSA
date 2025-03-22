class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image1, int sr, int sc, int color) {
        //must copy 
        vector<vector<int>> image = image1;
        // stroring intial val of start 
        int store=image[sr][sc];
        // egde case i misesd so damnnnn test cases dekhli bhai!! unpe dry run
        if(store==color){
            return image;
        }
        int n=image.size();
        int m=image[0].size();
        //bfs
        // {r,c}
        queue<pair<int,int>> q;
        //intialsed
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            // for neighbours
            int drow[]={-1,0,+1,0};
            int dcol[]={0,+1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==store ){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
            
        }
        return image;

    }
};