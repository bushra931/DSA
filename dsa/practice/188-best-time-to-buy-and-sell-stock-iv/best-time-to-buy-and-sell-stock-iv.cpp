class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        int k=2*K;
        vector<int> ahead(k+1,0);
        vector<int> curr(k+1,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int trans=k-1;trans>=0;trans--){
                 if(trans%2==0){
                    curr[trans]=max(-prices[ind]+ahead[trans+1],0+ahead[trans]);
            }
                else{
                    curr[trans]=max(prices[ind]+ahead[trans+1],0+ahead[trans]);
                }
            }
            ahead=curr;
        }
        return ahead[0];    
    }
};