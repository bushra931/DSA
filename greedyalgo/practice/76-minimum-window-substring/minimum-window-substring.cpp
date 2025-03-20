class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> hash;
        int s_index = -1, l = 0, r = 0, minlen = INT_MAX, cnt = 0;
        int n = s.size(), m = t.size();

        for (char c : t) {
            hash[c]++;  // Store frequency of characters in t
        }

        while (r < n) {
            if (hash[s[r]] > 0) cnt++; // Only increment if s[r] is needed
            hash[s[r]]--;  // Decrease the count in the window
            
            while (cnt == m) { // All characters matched
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    s_index = l;
                }

                hash[s[l]]++;  // Restore left character back
                if (hash[s[l]] > 0) cnt--; // If it was a needed character, decrease count
                l++;  // Shrink the window
            }

            r++;  // Expand the window
        }

        return (s_index == -1) ? "" : s.substr(s_index, minlen);
        
    }
};