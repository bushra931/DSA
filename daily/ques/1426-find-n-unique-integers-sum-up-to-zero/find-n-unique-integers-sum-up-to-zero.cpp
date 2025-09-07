class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);
        int i=0,j=n-1;
        int x;
        if(n%2!=0) x=(n-1)/2;
        else x=n/2;
        while(i<j){
            ans[i]=-x;
            i++;
            ans[j]=x;
            j--;
            x--;
        }
        return ans;
    }
};