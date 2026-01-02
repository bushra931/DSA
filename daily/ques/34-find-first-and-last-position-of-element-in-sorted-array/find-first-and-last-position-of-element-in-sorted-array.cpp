class Solution {
public:
    int firstpos(vector<int>& nums, int target){
        int left=0;int right=nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target) ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
    int lastpos(vector<int>& nums, int target){
        int left=0;int right=nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target) ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
          int start=firstpos(nums,target);
          if(start==-1) return {-1,-1};
          int end=lastpos(nums,target);
          return {start,end};
    }
};