class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        queue<pair<string,int>> q;
        q.push({beginword,1});
        // less tc access to ele
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        if(st.find(beginword)!=st.end()) st.erase(beginword);

        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endword) return step;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                // trying all possible word made
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                //making back so next char could change
                word[i]=original;
            }
        }


    return 0;    
    }
};