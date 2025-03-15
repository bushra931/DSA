class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,l=0,r=0;
        while(r<nums.size()-1){
            int fathest=0;
            for(int i=l;i<=r;i++){
                fathest=max(i+nums[i],fathest);

            }
            jump++;
            l=r+1;
            r=fathest;

        }
        return jump;

        
    }
};