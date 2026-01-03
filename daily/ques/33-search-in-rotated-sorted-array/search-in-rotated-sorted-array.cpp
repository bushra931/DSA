class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1; 
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                      ans=mid;
                      break;
                } 
            //left sorted
            if(nums[l]<=nums[mid]){
                if(nums[l] <= target && target < nums[mid]){
                    r=mid-1;
                }
                else l=mid+1;
            }
            //right sorted
            else{
                if(nums[mid] < target && target <= nums[r]){
                    l=mid+1;
                }
                else r=mid-1;
            }

        }
        return ans;
        
    }
};