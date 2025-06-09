class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+3, vector<int>(2, 0)); // Fully safe now!

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 1; buy >= 0; buy--){
                if(buy){
                    dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
                                        0 + dp[ind+1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind+2][1],
                                        0 + dp[ind+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};
