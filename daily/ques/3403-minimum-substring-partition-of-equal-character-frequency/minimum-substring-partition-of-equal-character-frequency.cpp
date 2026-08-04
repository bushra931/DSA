bool check(vector<int> &b) {

    int cnt = 0;

    for (int i = 0; i < 26; i++) {

        if (b[i] > 0) {

            if (cnt == 0) {
                cnt = b[i];
            }
            else if (cnt != b[i]) {
                return false;
            }
        }
    }

    return true;
}

class Solution {
public:
    int minimumSubstringsInPartition(string s) {

        int n = s.size();

        vector<int> dp(n + 1, 100000);

        string g = "." + s;

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            vector<int> freq(26, 0);

            for (int j = i; j >= 1; j--) {

                freq[g[j] - 'a']++;

                if (check(freq)) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n];
    }
};