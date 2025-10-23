class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos=0,neg=0;
        vector<int> res(n);
        for(int k=0;k<n;k++){
            if(nums[k]>0){
                res[pos*2]=nums[k];
                pos++;
            }
            else{
                res[neg*2 + 1] = nums[k];
                neg++;
            }
        }
        nums=res;
        return nums; 
    }
};