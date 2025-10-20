class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int i=1;
        int j=1;
        int ele=nums[0];
        while(j<n){
            if(ele<nums[j]){
                ele=nums[j];
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        return i;
    }
};