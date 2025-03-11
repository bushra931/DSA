
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
       
        for (int i = 0; i < nums.size(); i++) {
            int findnum = target - nums[i];  
            
            
            auto j = find(nums.begin() + i + 1, nums.end(), findnum);
            
            
            if (j != nums.end()) {
                ans.push_back(i);
                ans.push_back(distance(nums.begin(), j)); 
                break;  
            }
        }
        return ans;
    }
};