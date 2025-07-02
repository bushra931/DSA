class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n=g.size(),m=s.size();
        int l=0,r=0;
        while(l<m && r<n){
            if(g[r]<=s[l]){
                r=r+1;
            }
            l++;
        }
        return r;
      
    }
};
