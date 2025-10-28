class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int mini=nums[0];
        while(l<=h){
            int mid=l+(h-l)/2;
            mini=min(nums[mid],mini);
            //left sorted
            if(nums[l]<=nums[mid]){
                 mini=min(nums[l],mini);
                l=mid+1;
            }
            //right sorted
            else{
                 h=mid-1;  
            }

        }
        return mini;


        
    }
};