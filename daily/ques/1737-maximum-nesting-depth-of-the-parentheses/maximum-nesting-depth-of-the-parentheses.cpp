class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxcnt=0;
        for(char ch:s){
            if(ch=='(')cnt++;
            else if(ch==')') cnt--;
            else continue;
            maxcnt=max(cnt,maxcnt);

        }
        return maxcnt;
    }
};