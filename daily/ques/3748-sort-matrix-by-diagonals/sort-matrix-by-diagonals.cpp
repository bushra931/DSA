class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
       
        int row=0;
        for(int col=n-1;col>0;col--){
             vector<int> diagonal_value;
             int i=row,j=col;
             while(i<n &&j<n){
                diagonal_value.push_back(grid[i][j]);
                i=i+1;
                j=j+1;
             }
             sort(diagonal_value.begin(),diagonal_value.end());
            i=row,j=col;
            int k=0;
             while(i<n &&j<n){
                grid[i][j]=diagonal_value[k];
                k++;
                i++;
                j++;
             }
        }
        int col=0;
        for(int row=n-1;row>=0;row--){
             vector<int> diagonal_value;
             int i=row,j=col;
             while(i<n &&j<n){
                diagonal_value.push_back(grid[i][j]);
                i=i+1;
                j=j+1;
             }
             sort(diagonal_value.begin(),diagonal_value.end(),greater<int>());
            i=row,j=col;
            int k=0;
             while(i<n &&j<n){
                grid[i][j]=diagonal_value[k];
                k++;
                i++;
                j++;
             }

        }

    return grid;    
        
   }
};