class Solution {
public:
    // int f(int ind, int buy,vector<int>& prices,vector<vector<int>>& dp,int fee){
    //     //base case
    //     if(ind >= prices.size()) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     if(buy){
    //         return dp[ind][buy]=max(-prices[ind]+f(ind+1,0,prices,dp,fee),0+f(ind+1,1,prices,dp,fee));
    //     }
    //     else{
    //         //sell
    //         return dp[ind][buy]=max(prices[ind]-fee+f(ind+1,1,prices,dp,fee),0+f(ind+1,0,prices,dp,fee));
    //     }
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int aheadnotbuy,aheadbuy,currbuy,currnotbuy;
        aheadnotbuy=aheadbuy=0;
        for(int ind=n-1;ind>=0;ind--){
            currnotbuy=max(prices[ind]+aheadbuy,0+aheadnotbuy);
            currbuy=max(-prices[ind]-fee+aheadnotbuy,0+aheadbuy);
            aheadbuy=currbuy;
            aheadnotbuy=currnotbuy;
        }
        return aheadbuy;
    }
};