class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //search breaking
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        //check if all dec no breaking
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //swap with large
        for(int j=n-1;j>ind;j--){
            if(nums[j]>nums[ind]){
                swap(nums[j],nums[ind]);
                break;
            }
        }
        //now sort 
        reverse(nums.begin()+ind+1,nums.end());
        return;
        
    }
};