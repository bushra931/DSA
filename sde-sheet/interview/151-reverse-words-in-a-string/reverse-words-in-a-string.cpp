class Solution {
public:
    string reverseWords(string s) {
         int n = s.size();
        string ans = "", temp = "";
        int i = n - 1;

        while (i >= 0) {
            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ') i--;

            if (i < 0) break;

            temp = "";

            // Collect the current word
            while (i >= 0 && s[i] != ' ') {
                temp = s[i] + temp;
                i--;
            }

            // Add the word to the final result
            if (!ans.empty()) ans += " ";
            ans += temp;
        }

        return ans;
    }
};