class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(target==nums[mid]) return mid;
            //left sorted
            if(nums[l]<=nums[mid]){
                if(nums[mid]>target && nums[l]<=target) h=mid-1;
                else  l=mid+1;
            } 
            //right sorted
            else{
                if(nums[mid]<target && nums[h]>=target) l=mid+1;
                else h=mid-1;

            }
        }
        return -1;
    }
};