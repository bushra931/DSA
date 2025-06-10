class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
      int n=arr.size();
      vector<int> dp(n,1),cnt(n,1);
      int maxi=1;
      for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
          if(arr[i]>arr[prev]&& 1+dp[prev]>dp[i]){
            dp[i]=1+dp[prev];
            //inhert
            cnt[i]=cnt[prev];
          }
           else if(arr[i]>arr[prev]&& 1+dp[prev]==dp[i]){
            dp[i]=1+dp[prev];
            //inhert
            cnt[i]+=cnt[prev];
          }
          if(dp[i]>maxi){
            maxi=dp[i];
          }
        }
      }
      int nos=0;
      for(int i=0;i<n;i++){
        if(dp[i]==maxi) nos+=cnt[i];
      }
      return nos;
        
    }
};