class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        //dp[i][j][k]
        int n=s.size();
        if (s.empty()) return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1)));
        // base case -len1 
        for(int i=0;i<n;i++){
            for(int op=0;op<=k;op++){
                dp[i][i][op]=1;
            }
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                for(int op=0;op<=k;op++){
                    if(s[i]!=s[j]){
                        int  cost=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
                        dp[i][j][op]=max(dp[i][j-1][op],dp[i+1][j][op]);
                        if(op>=cost){
                            dp[i][j][op]=max(dp[i][j][op],2+ (i + 1 <= j - 1 ? dp[i + 1][j - 1][op-cost] : 0));
                        }
                    }
                    else{
                        dp[i][j][op]=max({2+ (i + 1 <= j - 1 ? dp[i + 1][j - 1][op] : 0),dp[i][j-1][op],dp[i+1][j][op]});
                    }
                }
            }
        }
        return dp[0][n-1][k];
        
    }
};