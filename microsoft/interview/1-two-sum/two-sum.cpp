class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> hashmap;
        //not ans(2) as itw will{0,0} vector defined
        vector<int> ans;
        for(int i=0;i<n;i++){
            hashmap[nums[i]]=i;
        }
        //complement 
        for(int i=0;i<n;i++){
            int comp=target-nums[i];
            //missed edge case i==hash[comp]
            if(hashmap.find(comp)!=hashmap.end() && i!=hashmap[comp]){
                ans.push_back(i);
                ans.push_back(hashmap[comp]);  
                return ans;       
             }
        }
        return {};
        
    }
};