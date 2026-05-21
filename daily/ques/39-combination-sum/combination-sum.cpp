class Solution {
public:
    void  unique_combo(int index,vector<int>& candidates,vector<int>& combo,vector<vector<int>>& ans,int target){
        if(target==0) {
            ans.push_back(combo);
            return;
        }
        if(index>=candidates.size() ||target<0) return;

        target-=candidates[index];
        combo.push_back(candidates[index]);
        unique_combo(index,candidates,combo,ans,target);
        target+=candidates[index];
        combo.pop_back();
        unique_combo(index+1,candidates,combo,ans,target);

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combo;
        vector<vector<int>> ans;
        unique_combo(0,candidates,combo,ans,target);
        return ans;
    }
};