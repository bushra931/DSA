class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead1(2, 0);
        vector<int> ahead2(2, 0);
        vector<int> curr(2, 0); // Fully safe now!

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 1; buy >= 0; buy--){
                if(buy){
                    curr[buy] = max(-prices[ind] + ahead1[0],
                                        0 + ahead1[1]);
                } else {
                    curr[buy] = max(prices[ind] + ahead2[1],
                                        0 + ahead1[0]);
                }
            }
            ahead2=ahead1;
            ahead1=curr;
        }

        return ahead1[1];
    }
};
