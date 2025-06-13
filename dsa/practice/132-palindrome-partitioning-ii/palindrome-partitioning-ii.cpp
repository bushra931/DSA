class Solution {
public:
    bool ispalindrome(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    int f(int i,string& s,vector<int>& dp){
        int n=s.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                int cost=1+f(j+1,s,dp);
                mincost=min(mincost,cost);
            }
        }
        return dp[i]=mincost;

    }
    int minCut(string& s) {
        vector<int> dp(s.size(),-1);
        return f(0,s,dp)-1;
        
    }
};