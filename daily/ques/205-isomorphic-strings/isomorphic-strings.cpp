class Solution {
public:
    string coded(string s){
        unordered_map<char,int> mpp;
        string ans="";
        int i=1;
        for(char ch:s){
            if(mpp.find(ch)!=mpp.end()) ans+=mpp[ch];
            mpp[ch]=i;
            ans+=mpp[ch];
            i++;
        }
        return ans;
    }
    bool isIsomorphic(string s, string t) {
        string s1=coded(s);
        string t1=coded(t);
        if(s1==t1) return true;
        return false;
    }
};