class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int n = s.size();
    int l = 0, r = 0;// 2 pointer le liye shuru me fow wiindow
    int  res = 0;

    while (r < n) {
        // agr woh already map me hoga and aur us window me hoga to us index +1 pe l krdo window ka
        if (map.find(s[r]) != map.end() && map[s[r]] >= l) {
            l = map[s[r]] + 1;
        }
        // save krte jao char vs index
        map[s[r]] = r;
        // jo max window size de update it 
        res = max(res, r - l + 1);
        //window ka size inc consodering next element
        r++;
    }

    return res;





        
    }
};