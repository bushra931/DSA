#include <vector>
using namespace std;

class Solution {
public:

    int m, n;

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis)
    {
        vis[r][c] = 1;

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(auto &d : dir)
        {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if(vis[nr][nc])
                continue;

            if(heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n,0));
        vector<vector<int>> atlantic(m, vector<int>(n,0));

        // Pacific Ocean (top row + left column)
        for(int i = 0; i < m; i++)
            dfs(i,0,heights,pacific);

        for(int j = 0; j < n; j++)
            dfs(0,j,heights,pacific);

        // Atlantic Ocean (bottom row + right column)
        for(int i = 0; i < m; i++)
            dfs(i,n-1,heights,atlantic);

        for(int j = 0; j < n; j++)
            dfs(m-1,j,heights,atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};