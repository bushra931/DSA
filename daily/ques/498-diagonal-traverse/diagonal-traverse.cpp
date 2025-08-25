class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int m=mat.size();
        int n=mat[0].size();
        vector<int> result(m*n);
        int row=0,col=0;
        for(int i=0;i<m*n;i++){
            result[i]=mat[row][col];
            if((row+col)%2==0){
                //up-right
                if(col==n-1) row++;
                else if(row==0) col++;
                else{
                    row--;
                    col++;
                }
            }
            else{
                //down-left
                if(row==m-1) col++;
                else if(col==0) row++;
                else{
                    row++;
                    col--;
                }
            }

        }
        return result;
    }
};