class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};