class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> modcount;
        modcount[0]=1;
        int prefixsum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int mod=prefixsum%k;
            if(mod<0) mod+=k;
            count+=modcount[mod];
            modcount[mod]++;

        }
        return count;     
    }
};