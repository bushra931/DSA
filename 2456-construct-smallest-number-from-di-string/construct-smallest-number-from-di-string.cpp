class Solution {
public:
// For example, given the pattern"IDID", we start by pushing1onto the stack because we always push the next number. Since the first character is'I', we immediately pop from the stack and append1to the result. Then we push2and, seeing the next'D', we push3instead of immediately appending. The'I'that follows tells us it's time to pop and append the numbers, so3and then2are added to the result, maintaining the required decreasing order. The process continues in this manner, ensuring that the number we build respects the pattern while remaining lexicographically smallest.

// Algorithm
// Initialize an empty stringresultto store the final smallest number.

// Use astacknamednumStackto manage digits based on the pattern.

// Iterate through thepattern:

// Pushindex + 1ontonumStack, ensuring numbers are pushed in increasing order.
// If at the end of the pattern or the current character is'I':
// Pop all elements fromnumStackand append them toresult, ensuring that decreasing sequences are handled before moving to the next increasing sequence.
// Returnresultas the smallest number following the given pattern.
    string smallestNumber(string pattern) {
        string result;
        stack<int> numstack;
        // iterate through pattern
        for(int index=0;index<=pattern.size();index++){
            // push the no next numebr onto the stack
              numstack.push(index+1);

            //   if I is encountered or we reach end, pop alll the stack elemnts 
            if(index==pattern.size()|| pattern[index]=='I'){
                while(!numstack.empty()){
                    result+=to_string(numstack.top());
                    numstack.pop();

                }
            }
        }
        return result;
    }
};



//Approach 5: Greedy Approach with Sliding Window Reversal
/*Intuition
A more structured approach to constructing the smallest number that fits the given pattern is to use agreedy strategy with a sliding window reversal technique. Instead of constructing the number from scratch, we begin with a baseline sequence of consecutive numbers (e.g.,123456789for a pattern of lengthn). This ensures that we always start with the smallest possible number and then modify it as needed to satisfy the given pattern.

The idea is to use two pointers:currentIndex, which traverses the pattern, andpreviousIndex, which marks the start of the segment that needs to be reversed after we encounter a'D'(Decreasing) character. Whenever we find an'I'(Increasing) or reach the end of the pattern, we reverse the segment betweenpreviousIndexandcurrentIndexto ensure that the digits follow the required decreasing order.

For each character in the pattern:

If the current character is'I', no modification is required because the sequence already maintains increasing order.
If the current character is'D', we continue moving until we find an'I'or reach the end of the pattern. Once we find an'I'or exhaust the pattern, we reverse the substring frompreviousIndextocurrentIndexto create the required decreasing order.
Consider an example where the pattern is"DDI":*/

// We initialize our sequence as"1234", since the pattern length is 3.
// The first character is'D', so we continue scanning until we reach an'I'. Once we reach the'I', we reverse the first three elements ("123" → "321").
// Since the final character is'I', no further modifications are needed, and we append the last digit as is.
// The final result is"3214".
// Algorithm
// Initialize a string calledresultto store the final result.

// Iterate through thepattern:

// UsecurrentIndexto traverse the pattern andpreviousIndexto mark the start of the substring that may need to be reversed.

// Append the value1 + currentIndextoresult.

// When necessary, reverse the substring starting frompreviousIndex:

// IfcurrentIndexreaches the end of the pattern or the current character in the pattern is'I':
// Create a temporary string (temp) and reverse the substring starting frompreviousIndextocurrentIndex.
// Updateresultby concatenating the part beforepreviousIndexand the reversed substring frompreviousIndexonward.
// UpdatepreviousIndextocurrentIndex + 1.
// Return the finalresultas a string.
class Solution {
public:
    string smallestNumber(string pattern) {
        string result;

        // Iterate through the pattern and build the result
        for (int currentIndex = 0, previousIndex = 0;
             currentIndex <= pattern.length(); ++currentIndex) {
            result += to_string(1 + currentIndex);

            // Reverse the substring starting from previousIndex when necessary
            if (currentIndex == pattern.length() ||
                pattern[currentIndex] == 'I') {
                reverse(result.begin() + previousIndex, result.end());
                previousIndex = currentIndex + 1;
            }
        }

        return result;
    }
};

/*Approach 6: Optimized Greedy Approach with Precomputed 'D' Segments
Intuition
The previous approach used a sliding window reversal to handle decreasing sequences efficiently. An alternate strategy would involve precomputing the number of consecutive'D's at each position. This allows us to directly determine the correct digit placement without the need for explicit reversal operations.

Instead of modifying an existing sequence as we traverse the pattern, we first scan the patternbackwardto compute an arrayarrD[i], where each entry represents the number of consecutive'D's that appear after the corresponding position. This precomputed information allows us to determine the exact digit that should be placed in each position without needing to reverse segments manually.

As we build the answer, we maintain two key values:

maxSoFar: The largest number assigned so far.
currMax: A helper variable to ensure that subsequent digits are placed in proper increasing order, preventing conflicts between previously placed numbers.
When encountering an'I', we simply assign the smallest available number, which ismaxSoFar + 1. However, when encountering a'D', we need to ensure that the digits form a descending order. To achieve this, we usearrD[i]to determine how far the descending sequence extends. Instead of constructing the decreasing sequence step by step, we calculate the correct number directly:

digit=1+maxSoFar+arrD[i]

This formula ensures that:

The assigned number is large enough to maintain the required descending order.
The sequence remains lexicographically minimal by assigning the smallest possible numbers that satisfy the constraints.*/

class Solution {
public:
    string smallestNumber(string pattern) {
        int patternLength = pattern.length();
        int maxSoFar = 0, currMax = 0, temp;

        // Array to store lengths of decreasing subsequences in the pattern
        vector<int> arrD(patternLength + 1, 0);

        // Compute the lengths of decreasing subsequences in the pattern
        for (int patternIndex = patternLength - 1; patternIndex >= 0;
             patternIndex--) {
            if (pattern[patternIndex] == 'D')
                // If 'D', increment the length of the decreasing sequence
                arrD[patternIndex] = arrD[patternIndex + 1] + 1;
        }

        string result = "";

        // Build the result string based on the pattern
        for (int position = 0; position <= patternLength; position++) {
            if (pattern[position] == 'I') {
                // If 'I', assign the next maximum digit and append it to the
                // result
                maxSoFar++;
                result += '0' + maxSoFar;

                // Update the max digit encountered so far
                maxSoFar = max(maxSoFar, currMax);

                // Reset current max for the next iteration
                currMax = 0;
            } else {
                // If 'D', calculate the appropriate digit and append it to the
                // result
                temp = 1 + maxSoFar + arrD[position];
                result += '0' + temp;

                // Update the current max value
                currMax = max(currMax, temp);
            }
        }

        return result;
    }
};
