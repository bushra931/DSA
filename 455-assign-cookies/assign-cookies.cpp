class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0;// l to point on size,r on greed
        while(l<m && r<n){
            if(s[l]>=g[r]){
                r++;
            }
            // yeh sbke liye hoga kyuki agr s[l] nhi kr pa rha g[r] to age wale g[r] ko bhi nhi kr payege kyuki sported h isliyye l++ hmesha 
            l++;
        }
        // r jispe woh khada hoga wahi value r ki ans hogi kyuki mnlo 0 se 2 khilye yani an r =3 pe ho aur 3 hi bacho nhi khya hai
        return r;
        
    }
};