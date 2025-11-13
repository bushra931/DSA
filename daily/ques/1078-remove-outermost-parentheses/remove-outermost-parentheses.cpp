class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth=0;
           for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) result.push_back('(');
                ++depth;
            } else { // ch == ')'
                --depth;
                if (depth > 0) result.push_back(')');
            }
        }
        return result;

    }
};