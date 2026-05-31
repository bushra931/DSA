#include <vector>
#include <string>
using namespace std;

class Solution {
    long long solve(int i, int j,
                    string& s,
                    string& t,
                    vector<vector<long long>>& dp) {

        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ways = 0;

        if (s[i] == t[j]) {
            ways += solve(i + 1, j + 1, s, t, dp);
            ways += solve(i + 1, j, s, t, dp);
        }
        else {
            ways += solve(i + 1, j, s, t, dp);
        }

        return dp[i][j] = ways;
    }

public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(
            n, vector<long long>(m, -1)
        );

        return (int)solve(0, 0, s, t, dp);
    }
};