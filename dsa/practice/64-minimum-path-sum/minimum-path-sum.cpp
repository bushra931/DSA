class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0); // Initialize a vector to store the previous row's minimum path sums

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0); // Initialize a temporary vector for the current row
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    temp[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
                else {
                    // Calculate the minimum path sum considering moving up and moving left
                    int up = matrix[i][j];
                    if (i > 0)
                        up += prev[j]; // Include the minimum path sum from above (previous row)
                    else
                        up += 1e9; // A large value if moving up is not possible (out of bounds)

                    int left = matrix[i][j];
                    if (j > 0)
                        left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                    else
                        left += 1e9; // A large value if moving left is not possible (out of bounds)

                    // Store the minimum path sum in temp[j]
                    temp[j] = min(up, left);
                }
            }
            prev = temp; // Update the previous row with the current row
        }

        // The final result is stored in prev[n-1], which represents the destination in the last column
        return prev[n - 1];
    }
};
