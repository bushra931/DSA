class Solution {
public:
    int func(vector<int>& nums, int goal){
        // subarray sum less than equal to goal 
        if(goal<0) return 0;
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=func(nums,goal)-func(nums,goal-1);
        return ans;      
    }
};