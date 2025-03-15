class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindx=0;
        for(int i=0;i<nums.size()-1;i++){
            //considering case if pos not reached byt any but we reach i for it 
            if(i>maxindx) return false;
            maxindx=max(maxindx,i+nums[i]);
        }
        return maxindx>=nums.size()-1;
        
    }
};