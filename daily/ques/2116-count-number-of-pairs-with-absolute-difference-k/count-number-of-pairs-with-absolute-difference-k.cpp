class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(k+nums[i]) ) cnt+=mpp[k+nums[i]];
            if(mpp.count(nums[i]-k)) cnt+=mpp[nums[i]-k];
            mpp[nums[i]]++;
        }
        return cnt;
    }
};