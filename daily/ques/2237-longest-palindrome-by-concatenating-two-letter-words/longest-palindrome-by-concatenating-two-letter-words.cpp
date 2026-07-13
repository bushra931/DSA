class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;
        int ans=0;
        for (string &word : words){
            string rev=word;
            reverse(rev.begin(), rev.end());
            if(freq[rev]>0){
                ans+=4;
                freq[rev]--;
            }
            else{
                freq[word]++;
            }
        }
        for(auto &it:freq){
            if(it.second>0 && it.first[1]==it.first[0]){
                ans+=2;
                break;
            }
        }
        return ans;
        
    }
};