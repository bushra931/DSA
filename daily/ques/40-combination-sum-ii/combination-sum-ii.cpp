class Solution {
public:
    void  unique_combo(int index,vector<int>& candidates,vector<int>& combo,vector<vector<int>>& ans,int target){
        if(target==0) {
            ans.push_back(combo);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
                combo.push_back(candidates[i]);
                unique_combo(i+1,candidates,combo,ans,target-candidates[i]);
                combo.pop_back();

        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
         vector<int> combo;
        vector<vector<int>> ans;
        unique_combo(0,candidates,combo,ans,target);
        return ans;
    }
};