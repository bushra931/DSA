class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string &beginWord, vector<string> &path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;

        unordered_map<string, int> level;
        queue<string> q;

        q.push(beginWord);
        level[beginWord] = 0;

        int L = beginWord.size();

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            int currLevel = level[curr];
            string word = curr;

            for (int i = 0; i < L; i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    word[i] = ch;

                    if (dict.count(word)) {
                        if (!level.count(word)) {
                            level[word] = currLevel + 1;
                            parent[word].push_back(curr);
                            q.push(word);
                        } 
                        else if (level[word] == currLevel + 1) {
                            parent[word].push_back(curr);
                        }
                    }
                }
                word[i] = original;
            }
        }

        if (!level.count(endWord)) return ans;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};
