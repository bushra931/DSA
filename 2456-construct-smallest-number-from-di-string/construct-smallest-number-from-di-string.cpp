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