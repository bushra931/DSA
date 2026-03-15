class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqp(26,0);
         vector<int> freqs(26,0);
         if(p.size()>s.size()) return {};
         vector<int> ans;
         int k=p.size();
         for(int i=0;i<k;i++){
            freqp[p[i]-'a']++;
            freqs[s[i]-'a']++;
         }
         if(freqp==freqs) ans.push_back(0);
         for(int i=k;i<s.size();i++){
            freqs[s[i]-'a']++;
            freqs[s[i-k]-'a']--;
            if(freqp==freqs) ans.push_back(i-k+1);
         }
         return ans;


        
    }
};