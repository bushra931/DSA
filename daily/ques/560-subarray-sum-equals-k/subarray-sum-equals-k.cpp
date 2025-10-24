class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int currentsum=0,count=0;
        unordered_map<int,int> prefixsum;
        prefixsum[0]=1;
        for(int i=0;i<n;i++){
            currentsum+=nums[i];
            int remainsum=currentsum-k;
            count+=prefixsum[remainsum];
            prefixsum[currentsum]+=1;
        }
        return count;
    }
};