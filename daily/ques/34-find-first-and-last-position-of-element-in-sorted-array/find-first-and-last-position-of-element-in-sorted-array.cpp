class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans_s=-1;
        int ans_e=-1;
        while(s<=e){
            if(nums[mid]==target){
                ans_s=mid;
                while(ans_s>=0 && nums[ans_s]==target) ans_s--;
                ans_e=mid;
                while(ans_e<nums.size() &&nums[ans_e]==target) ans_e++;
                return {ans_s+1,ans_e-1};
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return {ans_s,ans_e};
        
    }
};