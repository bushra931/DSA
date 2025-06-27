class Solution {
public:
    bool binaryserach(int row ,vector<vector<int>>& matrix,int target){
        int s=0;
        int e=matrix[row].size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return false;


    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int n=row*col;
        int s=0,e=n-1,mid=s+(e-s)/2;
        while(s<=e){
            int ri=mid/col;
            int ci=mid%col;
            if(matrix[ri][ci]==target) return true;
            else if(matrix[ri][ci]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return false;


        
    }
};