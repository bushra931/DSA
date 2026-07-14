class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int need=k-nums[i];
            if(mpp.find(need)!=mpp.end()){
                cnt++;
                mpp[need]--;
                if (mpp[need] == 0) mpp.erase(need);
            }
            else mpp[nums[i]]++;
        }
        return cnt;

        
    }
};