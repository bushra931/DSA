class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxf=0;
        unordered_map<int,int> freq;
        while(r<s.size()){
            freq[s[r]]++;
            maxf=max(maxf,freq[s[r]]);
            if((r-l+1)-maxf>k){
                freq[s[l]]--;
              
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;


        }
        return maxlen;
        
    }
};