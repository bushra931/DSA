class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0;
        int maxlen=0;
        int cost=0;
        for(int r=0;r<s.size();r++){
            cost+=abs((s[r]-'a')-(t[r]-'a'));
            if(cost>maxCost){
                cost-=abs((s[l]-'a')-(t[l]-'a'));
                l++;
            }
            maxlen=max(maxlen,r-l+1);

        }
        return maxlen;
        
    }
};