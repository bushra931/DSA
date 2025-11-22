class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }

        vector<pair<char, int>> items;
        for (auto &p : count) {
            items.push_back(p);
        }

        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string out;
        out.reserve(s.size());
        for (auto &p : items) {
            out.append(p.second, p.first);
        }

        return out; 
    }
};