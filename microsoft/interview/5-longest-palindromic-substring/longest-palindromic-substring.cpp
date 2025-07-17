class Solution {
public:
    int expandaroundcenter(string& s,int l,int r){
        while(l>=0 &&r<s.length() && s[l]==s[r]){
            l--;
            r++;

        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start=0,maxlen=1;
        for(int i=0;i<s.length();i++){
            int len1=expandaroundcenter(s,i,i);
            int len2=expandaroundcenter(s,i,i+1);
            int len=max(len1,len2);
            if(len>maxlen){
                start=i-(len-1)/2;
                maxlen=len;
            }
        }
        return s.substr(start,maxlen);

    
    }
};