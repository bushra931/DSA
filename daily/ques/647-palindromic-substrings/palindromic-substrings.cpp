class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> dp1(n, vector<int>(n, 0));

        // Length = 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            dp1[i][i] = 1;
        }

        // Length = 2
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 1;

            dp1[i][i + 1] = dp1[i][i] + dp1[i + 1][i + 1] + dp[i][i + 1];
        }

        // Length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1])
                    dp[i][j] = 1;

                dp1[i][j] = dp1[i][j - 1]
                          + dp1[i + 1][j]
                          - dp1[i + 1][j - 1]
                          + dp[i][j];
            }
        }

        return dp1[0][n - 1];
    }
};