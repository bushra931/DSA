class Solution {
public:
    void combsum(int ind,int sum,vector<vector<int>>& ans,vector<int>& ds,int k,int n){
        if(k<0 || sum>n) return;
        if(k==0 && sum==n) {
            ans.push_back(ds);
            return;
            }
        for(int i=ind;i<=9;i++){
            ds.push_back(i);
            combsum(i+1,sum+i,ans,ds,k-1,n);
            ds.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        combsum(1,0,ans,ds,k,n);
        return ans;
        
    }
};