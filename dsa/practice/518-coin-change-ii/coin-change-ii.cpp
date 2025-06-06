class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> prev(amount+1,0), curr(amount+1,0);
        
        prev[0] = 1;
        
        for(int ind=0; ind<coins.size(); ind++){
            curr[0] = 1;
            for(int T=1; T<=amount; T++){
                unsigned long long nottake = prev[T];
                unsigned long long take = 0;
                if(coins[ind] <= T){
                    take = curr[T - coins[ind]];
                }
                curr[T] = take + nottake;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};
