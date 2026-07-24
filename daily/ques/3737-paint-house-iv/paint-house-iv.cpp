class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        // A=0,B=1,C=2
         vector<vector<vector<long long>>> dp( n / 2,
            vector<vector<long long>>(3, vector<long long>(3, LLONG_MAX)));
          for(int col1=0;col1<3;col1++){
            for(int col2=0;col2<3;col2++){
                if(col1==col2) continue;
                dp[0][col1][col2]=cost[0][col1]+cost[n-1][col2];
            }
          }
          for(int row=1;row<n/2;row++){
             for(int col1=0;col1<3;col1++){
                for(int col2=0;col2<3;col2++){
                    if(col1==col2) continue;
                    long long prev_best=LLONG_MAX;
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            if(i==j) continue;
                            if(i==col1) continue;
                            if(j==col2) continue;
                            prev_best=min(prev_best,dp[row-1][i][j]);
                        }
                    }
                    if(prev_best!=LLONG_MAX){
                        dp[row][col1][col2]=prev_best+cost[row][col1]+cost[n-row-1][col2];
                    }


                }
             }
          }
            long long ans = LLONG_MAX;

            for (int left = 0; left < 3; left++) {
                for (int right = 0; right < 3; right++) {
                    if (left == right) continue;
                    ans = min(ans, dp[n / 2 - 1][left][right]);
                }
            }

            return ans;

    }
};