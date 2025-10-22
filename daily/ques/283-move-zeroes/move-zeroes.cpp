class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        for(int k=i;k<n;k++){
            nums[k]=0;
        }
        return; 
    }
};