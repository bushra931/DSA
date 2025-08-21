
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }

        int m = mat.size();
        int n = mat[0].size();
        int total_submatrices = 0;

        // Step 1: Pre-calculate heights for each cell.
        // This loop starts from row 1 because row 0 heights are just their own values.
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }

        // Step 2 & 3: Iterate through each cell as part of a histogram
        // and count rectangles.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) continue;

                // Current bar's height is the minimum height so far.
                int min_height = mat[i][j];

                // Expand leftwards from the current cell j.
                for (int k = j; k >= 0; --k) {
                    if (mat[i][k] == 0) break;
                    
                    // The tallest rectangle we can form is limited by the shortest bar.
                    min_height = std::min(min_height, mat[i][k]);
                    total_submatrices += min_height;
                }
            }
        }

        return total_submatrices;
    }
};