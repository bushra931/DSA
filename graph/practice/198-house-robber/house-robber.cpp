class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=0;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int nonpick=0+prev;
            int curr_i=max(pick,nonpick);
            prev2=prev;
            prev=curr_i;

        }
        return prev;
    }
};