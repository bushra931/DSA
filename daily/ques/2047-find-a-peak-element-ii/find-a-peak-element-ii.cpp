class Solution {
public:
    int maxElement(const vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int maxVal = INT_MIN, rowIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (mat[i][col] > maxVal) {
                maxVal = mat[i][col];
                rowIdx = i;
            }
        }
        return rowIdx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int n = mat.size(), m = mat[0].size();
            int low = 0, high = m - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                int row = maxElement(mat, mid);

                int left = (mid > 0) ? mat[row][mid - 1] : -1;
                int right = (mid < m - 1) ? mat[row][mid + 1] : -1;

                if (mat[row][mid] > left && mat[row][mid] > right)
                    return {row, mid};
                else if (left > mat[row][mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return {-1, -1};
    }
};