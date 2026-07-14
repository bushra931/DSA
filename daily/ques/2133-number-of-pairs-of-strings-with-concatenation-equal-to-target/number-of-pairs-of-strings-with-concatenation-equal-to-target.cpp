class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int> mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;
        int cnt=0;
        for(auto &s:nums){
            if(target.substr(0,s.size())!=s) continue;
            string need=target.substr(s.size());
            if(mpp.count(need)){
                cnt+=mpp[need];
                if(need==s) cnt--;
            }

        }
        return cnt;
    }
};