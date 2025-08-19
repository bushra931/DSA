class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        long long ans=0;
        for(auto &no:nums){
            if(no==0){
                cnt++;
                ans+=cnt;
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
};