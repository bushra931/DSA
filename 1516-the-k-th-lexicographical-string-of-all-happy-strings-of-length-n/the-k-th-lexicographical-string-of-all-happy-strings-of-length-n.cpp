class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        string result = "";
        int indexInSortedList = 0;

        // Generate happy strings and track the k-th string
        generateHappyStrings(n, k, currentString, indexInSortedList, result);
        return result;
    }

private:
    void generateHappyStrings(int n, int k, string &currentString,
                              int &indexInSortedList, string &result) {
        // If the current string has reached the desired length
        if (currentString.size() == n) {
            indexInSortedList++;  // Increment the count of generated strings

            // If this is the k-th string, store it in the result
            if (indexInSortedList == k) result = currentString;
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last one
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            currentString += currentChar;

            // Recursively generate the next character
            generateHappyStrings(n, k, currentString, indexInSortedList,
                                 result);

            // If the result is found, stop further processing
            if (result != "") return;

            // Backtrack by removing the last character
            currentString.pop_back();
        }
    }
};
// Tc->O(n) in below
class Solution {
public:
    string getHappyString(int n, int k) {
        // Calculate the total number of happy strings of length n
        int total = 3 * (1 << (n - 1));

        // If k is greater than the total number of happy strings, return an
        // empty string
        if (k > total) return "";

        string result(n, 'a');

        // Define mappings for the next smallest and greatest valid characters
        unordered_map<char, char> nextSmallest = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};

        // Calculate the starting indices for strings beginning with 'a', 'b',
        // and 'c'
        int startA = 1;
        int startB = startA + (1 << (n - 1));
        int startC = startB + (1 << (n - 1));

        // Determine the first character based on the value of k
        if (k < startB) {
            result[0] = 'a';
            k -= startA;
        } else if (k < startC) {
            result[0] = 'b';
            k -= startB;
        } else {
            result[0] = 'c';
            k -= startC;
        }

        // Iterate through the remaining positions in the result string
        for (int charIndex = 1; charIndex < n; charIndex++) {
            // Calculate the midpoint of the group for the current character
            // position
            int midpoint = (1 << (n - charIndex - 1));

            // Determine the next character based on the value of k
            if (k < midpoint) {
                result[charIndex] = nextSmallest[result[charIndex - 1]];
            } else {
                result[charIndex] = nextGreatest[result[charIndex - 1]];
                k -= midpoint;
            }
        }

        return result;
    }
};
