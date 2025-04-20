class Solution {
private:
    int solve(vector<int>& nums){
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
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        int ans1=solve(arr1);
        int ans2=solve(arr2);
        return max(ans1,ans2);
    }
};