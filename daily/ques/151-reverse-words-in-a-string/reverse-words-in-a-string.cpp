class Solution {
public:
    string reverseWords(string s) {
        string word="";
        string ans="";
        int n=s.size();
        int i=n-1;
        while(i>=0){
             while(i>=0 && s[i]==' ') i--;
             if(i<0) break;
             while(i >= 0 && s[i]!=' '){
                word=s[i]+word;
                i--;
             }
             if(!ans.empty()) ans=ans+' ';
             ans=ans+word;
             word="";
             i--;
        }
        return ans;
    }
};