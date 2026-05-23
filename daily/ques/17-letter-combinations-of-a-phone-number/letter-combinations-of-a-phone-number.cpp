class Solution {
public:
   void build(int ind,string digits,string current,vector<string>& ans,unordered_map<char, string>& mapping){
       if(ind==digits.size()){
           ans.push_back(current);
           return;
       }
       string letters=mapping[digits[ind]];
       for(char ch:letters){
            current.push_back(ch);
            build(ind+1,digits,current,ans,mapping);
            current.pop_back();
       }
   }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
         unordered_map<char, string> mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> ans;
        string current;
        build(0,digits,current,ans,mapping);
        return ans;
    }
};