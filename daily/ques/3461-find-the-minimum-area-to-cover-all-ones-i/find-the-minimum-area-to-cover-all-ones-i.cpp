class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxr=rows-1;
        int minr=0;
        int maxc=cols-1;
        int minc=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                   maxr=min(maxr,i);
                   minr=max(minr,i);
                   maxc=min(maxc,j);
                   minc=max(minc,j);
                }
            }
        }
        return (abs(maxr-minr)+1)*(abs(maxc-minc)+1);
        
    }
};