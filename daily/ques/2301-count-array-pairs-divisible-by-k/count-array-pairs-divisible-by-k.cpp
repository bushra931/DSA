class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long ans=0;
        for(int x:nums){
            int g=gcd(x,k);
            int need=k/g;
            for(auto &[d,cnt]:freq){
                if(d%need==0) ans+=cnt;
            }
            freq[g]++;
        }
        return ans;
    }
};