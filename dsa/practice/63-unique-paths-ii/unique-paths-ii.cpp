class Solution {
public:
    int paths(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or obstacle
        if (r >= m || c >= n || grid[r][c] == 1) return 0;

        // Base case: reached destination
        if (r == m - 1 && c == n - 1) return 1;

        // If already computed
        if (dp[r][c] != -1) return dp[r][c];

        // Move down and right
        return dp[r][c] = paths(r + 1, c, grid, dp) + paths(r, c + 1, grid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If starting point is an obstacle, no path
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(0, 0, obstacleGrid, dp);
    }
};
