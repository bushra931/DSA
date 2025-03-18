class Solution {
public:
    int numberOfSubstrings(string s) {
 int lastSeen[3] = {-1, -1, -1};  // Stores the last index of 'a', 'b', and 'c'
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        lastSeen[s[i] - 'a'] = i;  // Update last seen index of the current character

        // Ensure all three characters are seen
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            count += (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
        }
    }

    return count;
    }
};