class Solution {
public:
    static bool compareSecondElement(vector<int>& a, vector<int>& b) {
          return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int cnt = 1;
        int lastendtime=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=lastendtime){
                cnt++;
                lastendtime=intervals[i][1];
            }
        }
        return intervals.size()-cnt;
        
    }
};