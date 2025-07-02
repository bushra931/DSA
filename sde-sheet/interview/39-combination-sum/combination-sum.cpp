class Solution {
public:
    void findcombo(int ind,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds){
        if(ind==arr.size()){
            if(target==0) ans.push_back(ds);
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findcombo(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findcombo(ind+1,target,arr,ans,ds);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        findcombo(0,target,candidates,ans,ds);
        return ans;

    }
};