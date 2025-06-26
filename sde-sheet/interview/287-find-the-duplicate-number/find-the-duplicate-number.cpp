class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans;
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
            if(hash[nums[i]]>1){
                ans=nums[i];
                break;
            }
        } 
        return ans;   
    }
};