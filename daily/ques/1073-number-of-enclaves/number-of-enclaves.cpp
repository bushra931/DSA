class Solution {
public:
     void dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        grid[r][c] = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();

        // first and last row
        for (int c = 0; c < n; c++) {
            if (grid[0][c] == 1) dfs(0, c, grid);
            if (grid[m - 1][c] == 1) dfs(m - 1, c, grid);
        }

        // first and last column
        for (int r = 0; r < m; r++) {
            if (grid[r][0] == 1) dfs(r, 0, grid);
            if (grid[r][n - 1] == 1) dfs(r, n - 1, grid);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};