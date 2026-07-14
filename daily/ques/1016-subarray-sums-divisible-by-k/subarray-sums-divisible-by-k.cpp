class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> modcount;
        modcount[0]=1;
        int prefixsum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int rem=prefixsum%k;
            if(rem<0) rem+=k;
            if(modcount.count(rem)) ans+=modcount[rem];
            modcount[rem]++;
        }
        return ans;
        
    }
};