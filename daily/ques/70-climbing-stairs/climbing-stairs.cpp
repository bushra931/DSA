class Solution {
public:
    int climbStairs(int n) {
        int prev2=1,prev=1;
        for(int i=2;i<=n;i++){
            int onestep=prev;
            //2 step
            int twostep=prev2;
            int curr=onestep+twostep;
            prev2=prev;
            prev=curr;
        }
       
        return prev;
    }
};