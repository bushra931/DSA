class Solution {
public:
    int numTilePossibilities(string tiles) {
        //track frequency of char in tiles
        int charcount[26];
        for(char c :tiles){
            charcount[c-'A']++;
        }
        // find all posible sequence with sequence count 
        return sequencecount(charcount);
    }
    int sequencecount(int charcount[26]){
        int totalcount=0;
        //// Try using each available character
        for(int pos=0;pos<26;pos++){
            if(charcount[pos]==0) continue;
            totalcount++;
            charcount[pos]--;
            totalcount+=sequencecount(charcount);
            charcount[pos]++;
        }
        return totalcount;
    }
};