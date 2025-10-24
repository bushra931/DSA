class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;

        int top = 0, bottom = row - 1;
        int left = 0, right = col - 1;

        while (top <= bottom && left <= right) {
            // top row
            for (int c = left; c <= right; c++)
                ans.push_back(matrix[top][c]);
            top++;

            // right column
            for (int r = top; r <= bottom; r++)
                ans.push_back(matrix[r][right]);
            right--;

            // bottom row
            if (top <= bottom) {
                for (int c = right; c >= left; c--)
                    ans.push_back(matrix[bottom][c]);
                bottom--;
            }

            // left column
            if (left <= right) {
                for (int r = bottom; r >= top; r--)
                    ans.push_back(matrix[r][left]);
                left++;
            }
        }
        return ans;
    }
};