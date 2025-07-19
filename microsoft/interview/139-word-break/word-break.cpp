class Solution {
public:
    bool func(int start,string &s,vector<int> &dp, unordered_set<string> &dict){
        if(start==s.length()) return true;
        if(dp[start]!=-1) return dp[start];
        for(int end=start+1;end<=s.length();end++){
            string word=s.substr(start,end-start);
            if(dict.count(word)&& func(end,s,dp,dict)){
                return dp[start]=true;
            }
        }
        return dp[start]=false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.length()+1,-1);
        return func(0,s,dp,dict);
        
    }
};