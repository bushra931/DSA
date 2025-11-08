class Solution {
public:
    bool divisor_sum(vector<int>& nums,int mid, int threshold){
        int sum=0;
        for(int it:nums){
            sum+=(it+mid-1)/mid;
            if(sum>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(divisor_sum(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }
            else {
               low=mid+1;
            }
        }
        return ans;
    }
};