class Solution {
public:
    int balancedString(string s) {
             unordered_map<char, int> freq;

            // Frequency of the whole string
            for (char ch : s)
                freq[ch]++;

            int n = s.size();
            int need = n / 4;

            // Already balanced
            if (freq['Q'] == need &&
                freq['W'] == need &&
                freq['E'] == need &&
                freq['R'] == need)
                return 0;

            int left = 0;
            int ans = n;

            for (int right = 0; right < n; right++) {

                // Character enters the replace window,
                // so remove it from the outside frequency.
                freq[s[right]]--;

                while (freq['Q'] <= need &&
                    freq['W'] <= need &&
                    freq['E'] <= need &&
                    freq['R'] <= need) {

                    ans = min(ans, right - left + 1);

                    // Remove left character from the window,
                    // so it comes back outside.
                    freq[s[left]]++;
                    left++;
                }
            }

            return ans;
        
    }
};