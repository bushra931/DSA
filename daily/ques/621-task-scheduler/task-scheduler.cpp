class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> freq(26, 0);

        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());

        int cntMax = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                cntMax++;
            }
        }

        int slots = (maxFreq - 1) * (n + 1) + cntMax;

        return max((int)tasks.size(), slots);
        
    }
};