class Solution {
public:
    string reverseWords(string s) {
      int left = 0, right = s.length() - 1;
        
        // Step 1: Trim leading and trailing spaces
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        vector<string> words;
        string temp = "";
        
        // Step 2: Traverse the string and extract words
        while (left <= right) {
            if (s[left] != ' ') {
                temp += s[left];  // Build the word
            } else if (!temp.empty()) {  
                words.push_back(temp);  // Store completed word
                temp = "";  // Reset for next word
            }
            left++;
        }
        
        // Step 3: Push the last word (if any)
        if (!temp.empty()) {
            words.push_back(temp);
        }

        // Step 4: Construct the final reversed string
        string ans = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i] + (i > 0 ? " " : ""); // Add space only between words
        }

        return ans;   
    }
};