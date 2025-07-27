class Solution {
public:
    bool isValid(int newr, int newc, int m,int n) {
        return newr >= 0 && newr < m && newc >= 0 && newc < n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        int anst=grid[0][0];
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int ele=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            vis[r][c]=1;
            anst=max(ele,anst);
            if(r==m-1 && c==n-1) return anst; 
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(isValid(newr,newc,m,n) && !vis[newr][newc]){
                    pq.push({grid[newr][newc],{newr,newc}});
                }
            }

        }
        return anst;
        
    }
};