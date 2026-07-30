class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int ans[n][n];
        for(int i=0;i<n;i++){
            ans[i][i]=nums[i];
        }
        int len=2;
        while(len<=n){
            for(int i=0; i<=n-len; i++){
                int j = i+len-1;
                ans[i][j] = (ans[i][j-1]^ans[i+1][j]);
            }
            len++;

            }
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0; i<n; i++)
        dp[i][i] = nums[i];

        for(int i=0; i<n-1; i++)
        dp[i][i+1] = max(ans[i][i+1],max(dp[i][i],dp[i+1][i+1]));

        int length = 3;
        while(length <= n){
            for(int i=0; i<=n-length; i++){
                int j = i+length-1;
                dp[i][j] = max(ans[i][j],max(dp[i][j-1],dp[i+1][j]));
            }
            length++;
        }

        // Now directly give answer of all queries from dp array 
        vector<int> q;

        for(int k=0; k<queries.size(); k++){
            int i = queries[k][0];
            int j = queries[k][1];

            q.push_back(dp[i][j]);
        } 

        return q;
        
    }
};